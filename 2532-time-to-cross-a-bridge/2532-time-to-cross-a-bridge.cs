using System.Diagnostics;

	public class Solution
	{
		[Conditional("DEBUG")]
		void debugMessage(string message)
		{
			//Console.WriteLine(message);
		}

		class Worker
		{
			public int ID { get; }
			public int RightToLeftTime { get; }
			public int LeftToRightTime { get; }

			public int TotalMoveTime { get; }

			public int PickUpBox { get; }
			public int PutDownABox { get; }

			public int CurrentBoxTime = 0;

			public Worker(int id, int leftToRightTime, int pickUp, int rightToLeftTime, int putDown)
			{
				this.ID = id;

				this.LeftToRightTime = leftToRightTime;
				this.RightToLeftTime = rightToLeftTime;
				this.TotalMoveTime = LeftToRightTime + RightToLeftTime;

				this.PickUpBox = pickUp;
				this.PutDownABox = putDown;
			}

			public void WorkOnTask(int time)
			{
				CurrentBoxTime -= time;
			}
		}

		class WaitForBridgeComparer : IComparer<Worker>
		{
			public int Compare(Worker x, Worker y)
			{
				if (x.TotalMoveTime > y.TotalMoveTime)
				{
					return -1;
				}
				else if (x.TotalMoveTime < y.TotalMoveTime)
				{
					return 1;
				}
				else
				{
					return y.ID - x.ID;
				}
			}
		}

		public int FindCrossingTime(int numBoxes, int numWorkers, int[][] time)
		{
			//https://leetcode.com/problems/time-to-cross-a-bridge/

			WaitForBridgeComparer comparer = new WaitForBridgeComparer();
			var waitingToGoRight = new SortedSet<Worker>(comparer);
			var waitingToGoLeft = new SortedSet<Worker>(comparer);
			int timeTaken = 0;

			// TODO: Could cache this, so we don't have to search for the lowest current task remaining time
			var pickingUpFromRight = new HashSet<Worker>();
			var puttingDownOnLeft = new HashSet<Worker>();

			List<Worker> workers = new List<Worker>();

			for (int workerIndex = 0; workerIndex < numWorkers; workerIndex++)
			{
				int[] workerTimes = time[workerIndex];
				Worker worker = new Worker(workerIndex, workerTimes[0], workerTimes[1], workerTimes[2], workerTimes[3]);
				workers.Add(worker);
				waitingToGoRight.Add(worker);
			}

			void doBoxWork(int time)
			{
				// Decrement picker ups
				List<Worker> toRemove = new List<Worker>();
				foreach (Worker worker in pickingUpFromRight)
				{
					worker.WorkOnTask(time);
					if (worker.CurrentBoxTime <= 0)
						toRemove.Add(worker);
				}
				foreach (Worker worker in toRemove)
				{
					debugMessage($"Worker {worker.ID} has finished picking up");
					pickingUpFromRight.Remove(worker);
					waitingToGoLeft.Add(worker);
				}
				toRemove.Clear();

				// Decrement dropper offers
				foreach (Worker worker in puttingDownOnLeft)
				{
					worker.WorkOnTask(time);
					if (worker.CurrentBoxTime <= 0)
						toRemove.Add(worker);
				}
				foreach (Worker worker in toRemove)
				{
					debugMessage($"Worker {worker.ID} has finished putting down");
					puttingDownOnLeft.Remove(worker);
					waitingToGoRight.Add(worker);
				}

				timeTaken += time;
			}

			// Check if anyone is waiting to go across bridge, if so, cross bridge, increment eveyrones task count by bridge cross time
			// If no one is waiting on bridge, increment all times by lowest remainging task time
			// Repeat

			while (numBoxes > 0 || waitingToGoLeft.Count > 0 || pickingUpFromRight.Count > 0)
			{

				// Check if anyone is waiting to go across bridge, if so, cross bridge, increment eveyrones task count by bridge cross time

				//            If a worker x reaches the bridge while another worker y is crossing the bridge, x waits at their side of the bridge.
				//If the bridge is free, the worker waiting on the right side of the bridge gets to cross the bridge.If more than one worker is waiting on the right side, the one with the lowest efficiency crosses first.
				//If the bridge is free and no worker is waiting on the right side, and at least one box remains at the old warehouse, the worker on the left side of the river gets to cross the bridge.If more than one worker is waiting on the left side, the one with the lowest efficiency crosses first.

				if (waitingToGoLeft.Count > 0)
				{
					Worker walker = waitingToGoLeft.First();
					waitingToGoLeft.Remove(walker);

					debugMessage($"Working {walker.ID} has gone to drop off");

					// Decrement task time by walk time
					doBoxWork(walker.RightToLeftTime);

					// Putting it down
					walker.CurrentBoxTime = walker.PutDownABox;
					puttingDownOnLeft.Add(walker);
				}
				else if (waitingToGoRight.Count > 0 && numBoxes > 0)
				{
					Worker walker = waitingToGoRight.First();
					waitingToGoRight.Remove(walker);

					debugMessage($"Working {walker.ID} has gone to pickup");

					// Decrement task time by walk time
					doBoxWork(walker.LeftToRightTime);
					numBoxes--;

					// Start picking up box
					walker.CurrentBoxTime = walker.PickUpBox;
					pickingUpFromRight.Add(walker);
				}
				else if (pickingUpFromRight.Count > 0 || puttingDownOnLeft.Count > 0)
				{
					// Find the lowest remaining task time
					int taskTime = pickingUpFromRight.Concat(puttingDownOnLeft).Min(w => w.CurrentBoxTime);


					// Do the work
					doBoxWork(taskTime);
				}
			}

			return timeTaken;
		}

	}
