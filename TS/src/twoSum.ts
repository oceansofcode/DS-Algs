import { describe, it } from 'mocha';
import { should } from 'chai';

/* eslint-disable immutable/no-let */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const twoSum = (nums: number[], target: number): number[] => {
   const sortedNums = nums.filter(num => num <= target).sort();
   const sortedNumLength = sortedNums.length;
   let foundNumbers: number[];

   for (let i = 0; i < sortedNumLength - 1; i++) {
      const firstNum = sortedNums[i];
      for (let j = i + 1; j < sortedNumLength; j++) {
         const secondNum = sortedNums[j];

         if (target - firstNum == secondNum) {
            foundNumbers = [i, j];
            break;
         }

      }

      if (foundNumbers) {
         break;
      }
   }

   return foundNumbers;
};

should();

describe('Test cases', () => {
   it('should equal [1, 2]', () => {
      twoSum([3, 2, 4], 6).should.equal([1, 2]);
   });
});
