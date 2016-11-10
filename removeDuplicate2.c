/* Remove Duplicates from Sorted Array II
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.*/ 

int removeDuplicates(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return 0;
    
    int i = 0;
    int len = 0;
    int flag = 0;
    for( i = 1; i < numsSize; ++i){
        if(*(nums + len) == *(nums + i) && flag == 0){
            ++len;
            *(nums + len) = *(nums + i);
            flag = 1;
            continue;
        }
        
        if(*(nums + len) != *(nums + i)){
            flag = 0;
            ++len;
            *(nums + len) = *(nums +i);
        }
    }
    return len + 1;
}