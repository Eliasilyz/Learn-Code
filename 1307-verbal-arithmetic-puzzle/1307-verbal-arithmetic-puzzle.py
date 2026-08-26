class Solution:
	def isSolvable(self, words: List[str], result: str) -> bool:
		v = defaultdict(int)
		resa = set()
		n = 0
		for i in range(len(words)):
			word = words[i]
			words[i] = words[i][::-1]
			l = len(word)
			if l > 1:
				resa.add(word[0])
			n = max(n, l)
			for j in range(l):
				v[word[j]] = None
		result = result[::-1]
		for i in result:
			v[i] = None
		m, n = len(words), max(n, len(result))
		grid = [[0 for i in range(n)] for j in range(m)]
		for i in range(m):
			x = len(words[i])
			for j in range(x):
				grid[i][j] = words[i][j]
		# for row in grid:
		#     print(*row)
		# print(*result)
		if len(result) > 1:
			resa.add(result[-1])
		visited = [False for i in range(10)]
		def solve(i, j, res):
			nonlocal resa
			nonlocal visited
			for z in resa:
				if v[z] == 0:
					return False
			if j == n:
				return res == 0
			if i == m:
				if j < len(result):
					val = result[j]
					if v[val] != None:
						if v[val] == res%10:
							if solve(0, j+1,res//10):
								return True
						return False
					for x in range(10):
						if visited[x]:
							continue
						visited[x] = True
						v[val] = x
						if solve(i, j, res):
							return True
						v[val] = None
						visited[x] = False
					return False
				else:
					if res == 0 and solve(0,j+1,res):
						return True
					return False

			val = grid[i][j]
			if grid[i][j] == 0:
				if solve(i+1, j, res):
					return True
				return False
			if v[val] != None:
				if solve(i+1, j, res+v[val]):
					return True
				return False
			for x in range(10):
				if visited[x]:
					continue
				visited[x] = True
				val = grid[i][j]
				v[val] = x
				if solve(i+1, j, res+x):
					return True
				v[val] = None
				visited[x] = False
			return False
		return solve(0,0,0)