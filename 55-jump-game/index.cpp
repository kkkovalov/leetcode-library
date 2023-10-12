#include <iostream>
#include <vector>

bool maxReach (std::vector<int>& nums, int finalPosition, int currentPosition) {
    if (currentPosition == finalPosition)
    {
        std::cout << "reached\n";
        return true;
    };
    for (int jumpLength = nums[currentPosition]; jumpLength > 0; --jumpLength) {
        if (currentPosition + jumpLength >= finalPosition) return true;
        else if (nums[currentPosition + jumpLength] != 0) {
            maxReach (nums, finalPosition, currentPosition + jumpLength);
        }
    }
    return false;
};

bool canJump (std::vector<int>& nums) {
    if (nums.size () == 1) return true;
    if (nums[0] == 0) return false;

    int finalPosition = nums.size () - 1;
    return maxReach (nums, finalPosition, 0);
};



int main () {
    std::vector<int> nums{ 3,0,8,2,0,0,1 };
    std::cout<< canJump(nums);

    return 0;
};
