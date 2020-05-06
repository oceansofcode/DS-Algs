"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const mocha_1 = require("mocha");
const chai_1 = require("chai");
/* eslint-disable immutable/no-let */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const twoSum = (nums, target) => {
    const sortedNums = nums.filter(num => num <= target).sort();
    const sortedNumLength = sortedNums.length;
    let foundNumbers;
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
chai_1.should();
mocha_1.describe('Test cases', () => {
    mocha_1.it('should equal [1, 2]', () => {
        twoSum([3, 2, 4], 6).should.equal([1, 2]);
    });
});
