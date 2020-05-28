fn main() {
    let nums = vec![0, 1, 5, 7];
    const TARGET: i32 = 8;

    let correct_indices = two_sum(nums, TARGET);

    for elem in correct_indices {
        println!("{}", elem);
    }
}

fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut indicies: Vec<i32> = Vec::new();
    let mut index_one = 0;
    let num_length = nums.len();

    while index_one < num_length {
        let first_num = nums[index_one];
        let mut index_two = index_one + 1;
        let mut correct_indices = false;

        while index_two < num_length {
            let second_num = nums[index_two];
            let added_value = first_num + second_num;
            correct_indices = added_value == target;

            if correct_indices {
                indicies.push(index_one as i32);
                indicies.push(index_two as i32);
                break;
            }

            index_two = index_two + 1;
        }

        if correct_indices {
            break;
        }

        index_one = index_one + 1;
    }

    indicies
}
