/* eslint-disable immutable/no-let */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
export const twoSum = (nums: number[], target: number): number[] => {
   const filteredNums = [];
   const numsLength: number = nums.length;
   const indexMap: Map<number, number> = new Map();
   let foundNumbers: number[];

   // O(n)
   for (let i = 0; i < numsLength; i++) {
      if (nums[i] <= target) {
         indexMap.set(nums[i], i);
         filteredNums.push(nums[i])
      }
   }

   // O(nlogn)
   const sortedNums = filteredNums.sort();
   const sortedNumLength = sortedNums.length;

   for (let i = 0; i < sortedNumLength - 1; i++) {
      const firstNum = sortedNums[i];
      for (let j = i + 1; j < sortedNumLength; j++) {
         const secondNum = sortedNums[j];
         if (target - firstNum == secondNum) {
            foundNumbers = [indexMap.get(firstNum), indexMap.get(secondNum)];
            break;
         }
      }

      if (foundNumbers) {
         break;
      }
   }

   return foundNumbers;
};

console.log(twoSum([3, 2, 4], 6)); // Should equal [1, 2]
console.log(twoSum([3, 3], 6)); // Should equal [0, 1]