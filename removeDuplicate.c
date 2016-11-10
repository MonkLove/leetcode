 /*   Remove Duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.*/ 


int removeDuplicates(int* nums, int numsSize) 
{
    
    if(nums == NULL || numsSize == 0)
        
        return 0;
        

#if 1
   
    int i = 0;
    
    int count = 0;
    
    for(i = 0; i < numsSize - 1; ++i){
        
        if(*(nums + i) != *(nums + i + 1)){
            
            ++count;
            
            *(nums + count) = *(nums + i + 1);
        
        }
    
    }
    
    

#else
    
    int i;
    
    int count = numsSize;
    
    
    for(i = numsSize - 1; i > 0; --i){
        
        if(*(nums + i) == *(nums + i -1)){
            
            *(nums + i) = *(nums + count - 1);    /*switch the duplicates num with the last element in array*/
            
            count--;
        
        }
    
    }
    

    /*sort the new array*/
    
    int tmp = 0;
    
    for(i = 0; i < count; ++i){
        
        for(int j = 0; j < count - i - 1; ++j){
            
            if(*(nums + j) > *(nums + j + 1)){
                
                tmp = *(nums + j);
                
                *(nums +j) = *(nums + j +1);
                
                *(nums + j + 1) = tmp;
            
            }
        
        }
    
    }

#endif

    
    return count + 1;

}