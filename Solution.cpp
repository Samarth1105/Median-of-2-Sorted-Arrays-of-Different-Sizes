class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2){
        int n= array1.size();
        int m= array2.size();
        
        // array1 should be smaller
        if(n>m) return MedianOfArrays(array2, array1);
    
        int leftElements = (n+m+1)/2;
        int low=0, high=n;
        
        while(low<=high){
            int mid1= low + (high-low)/2;
            int mid2 = leftElements- mid1;
            
            int l1= (mid1==0 ? INT_MIN : array1[mid1-1]);
            int l2= (mid2==0 ? INT_MIN : array2[mid2-1]);
            
            int r1= (mid1==n ? INT_MAX : array1[mid1]);
            int r2= (mid2==m ? INT_MAX : array2[mid2]);
            
            if(l1<=r2 && l2<=r1){
                if((n+m)%2==1){
                    return (double)(max(l1,l2));
                }
                else{
                    return (double)((min(r1,r2)+ max(l1,l2))/2.0);
                }
            }
            if(l1>r2){
                high = mid1-1;
            }
            else{
                low=mid1+1;
            }
        }
        return 0;
    }
};
