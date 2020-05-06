import { describe, it } from 'mocha';
import { should } from 'chai';
import { twoSum } from './twoSumP';

should();

describe('Test cases', () => {
   it('should take ([3, 2, 4], 6) and output [1, 2]', () => {
      twoSum([3, 2, 4], 6).should.eql([1, 2]);
   });

   it('should take ([3, 3], 6) and output [0, 1]'), () => {
      twoSum([3, 3], 6).should.eql([0, 1]);
   }
});
