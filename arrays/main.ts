
(function main() {
  let myArr = [2, 1, 5, 7, 3, 4];
  const sortedArr = [1, 2, 3, 4, 5, 7];

  myArr = bubbleSort(myArr);

  for (let i = 0; i < sortedArr.length; i++) {
    console.assert(sortedArr[i] === myArr[i], "numbers Match");
  }

  console.log(sortedArr);

})();

function bubbleSort(arr: number[]): number[] {
  let totalRuns = 0;
  for (let i = arr.length; i > 0; i--) {
    for (let j = 0; j < i; j++) {
      console.log(`i: ${i}: j: ${j}`);
      totalRuns++;
      if (arr[j] > arr[j + 1]) {
        // Using XOR we can swap numbers without an extra variable
        arr[j] ^= arr[j + 1];
        arr[j + 1] = arr[j] ^ arr[j + 1];
        arr[j] ^= arr[j + 1];
      }
    }
  }

  console.log(`BubbleSort total runs: ${totalRuns}. Worst case runs (O(n^2)): ${arr.length ** 2}`);
  return arr;
}