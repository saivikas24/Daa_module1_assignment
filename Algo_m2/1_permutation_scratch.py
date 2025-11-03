def permute(arr,left,right):
   #Base condition: if we fix all positions, print one permutation
   if left == right:
       print(arr)
       
   else:
   #Try all possible elements for current position
     for i in range(left,right+1):
       #step1:swapping current index with i
       arr[left],arr[i]=arr[i],arr[left]
       
       #step 2: recurse for the next position
       permute(arr,left+1,right)
       
       #step 3: Backtrack (swap again to orginal)
       arr[left],arr[i]=arr[i],arr[left]
       
arr=[1,2,3]
permute(arr,0,len(arr)-1)
       