"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
/* eslint-disable immutable/no-let */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
exports.twoSum = (nums, target) => {
    const filteredNums = [];
    const numsLength = nums.length;
    const indexMap = new Map();
    let foundNumbers;
    // O(n)
    for (let i = 0; i < numsLength; i++) {
        if (nums[i] <= target) {
            indexMap.set(nums[i], i);
            filteredNums.push(nums[i]);
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
//# sourceMappingURL=twoSum.js.map