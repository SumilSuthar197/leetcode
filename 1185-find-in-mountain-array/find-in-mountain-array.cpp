/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakElement(MountainArray &Arr){
        int s=0,e=Arr.length()-1,mid;
        while(s<e){
            mid=s+(e-s)/2;
            if(Arr.get(mid)>Arr.get(mid+1)) e=mid;
            else s=mid+1;
        }
        return e;
    }
    int binarySearchFnR(MountainArray &v, int k,int start,int end){
        int mid;
	    while(start<=end){
            mid=start+(end-start)/2;
            int ans=v.get(mid);
		    if(ans == k) return mid;
            if(ans < k) end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
    int binarySearchFnL(MountainArray &v, int k,int start,int end){
        int mid;
	    while(start<=end){
            mid=start+(end-start)/2;
            int ans=v.get(mid);
		    if(ans == k) return mid;
            if(ans > k) end=mid-1;
            else start=mid+1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak=peakElement(mountainArr);
        int res=binarySearchFnL(mountainArr,target,0,peak);
        if(res==-1) return binarySearchFnR(mountainArr,target,peak,mountainArr.length()-1); 
        return res;        
    }
};