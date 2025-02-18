
(function main() {
  const sortedArr = [1, 2, 3, 4, 5, 7];
  const unsortedArr = [2, 1, 5, 7, 3, 4];

  console.log('unsorted', unsortedArr);

  const bubbled = bubbleSort([...unsortedArr]); // Create a copy since this bubble sort is in-place
  const selected = selectionSort([...unsortedArr]);

  for (let i = 0; i < sortedArr.length; i++) {
    console.assert(sortedArr[i] === bubbled[i], "numbers Match");
  }

  console.log(bubbled);
  console.log(selected);

  // console.log(binarySearch(sortedArr, 0, sortedArr.length, 3));

})();

// Wip
function binarySearch(arr: number[], low: number, high: number, searchItem: number): number {

  if (high >= low) {
    const mid = Math.floor((high - low) / 2); // Flooring so we need to be mindful that we do not lose this index.

    const currentItem = arr[mid];

    console.log(`low: ${low}. high: ${high}. mid ${mid}`);

    if (currentItem === searchItem) {
      return mid;
    } else if (searchItem > currentItem) { // Item must be in the higher sub array
      return binarySearch(arr, mid + 1, high, searchItem);
    } else if (searchItem < currentItem) { // item must be in the lower sub array
      return binarySearch(arr, low, mid - 1, searchItem);
    }
  }

  return -1;
}

function bubbleSort(arr: number[]): number[] {
  let totalRuns = 0;
  for (let i = arr.length; i > 0; i--) {
    for (let j = 0; j < i; j++) {
      totalRuns++;
      if (arr[j] > arr[j + 1]) {
        arr[j] ^= arr[j + 1];
        arr[j + 1] = arr[j] ^ arr[j + 1];
        arr[j] ^= arr[j + 1];
      }
    }
  }

  console.log(`BubbleSort total runs: ${totalRuns}. Worst case runs (O(n^2)): ${arr.length ** 2}`);
  return arr;
}

function selectionSort(arr: number[]): number[] {
  let totalRuns = 0;

  for (let i = 0; i < arr.length; i++) {

  }


  console.log(`selectionSort total runs: ${totalRuns}. Worst case runs (O(n^2)): ${arr.length ** 2}`);

  return arr;
}