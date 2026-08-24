/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    // Check for invalid input
    if (rowsCount * colsCount !== this.length) {
      return [];
    }
  
    const result = [];
    for (let col = 0; col < colsCount; col++) {
    const currentRow = [];
    for (let row = 0; row < rowsCount; row++) {
        currentRow.push(this[col * rowsCount + row]);
      }
      if (col % 2 === 0) {
        // If row is even, push the currentRow as it is
        result.push(currentRow);
      } else {
        // If row is odd, reverse the currentRow before pushing
        result.push(currentRow.reverse());
      }
    }
//   output=result;

  let out=result.reduce((arr1,arr2)=>{
    arr2.forEach((ele,index)=>{
        if(!arr1[index]){
            arr1[index]=[];
        }
        arr1[index].push(ele);
    })
    return arr1
  },[])
  return out;
  };

// Example usage






/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */