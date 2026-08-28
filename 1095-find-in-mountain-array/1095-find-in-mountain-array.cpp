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
    int findPeak( MountainArray &mountainArr){
        int n = mountainArr.length() ;
        int l = 0 ;
        int r = n - 1 ;
        while(l < r){
            int mid = l+(r - l)/2 ;
            if(mountainArr.get(mid + 1) > mountainArr.get(mid)){
                    l = mid + 1 ;
                }else{
                    r = mid  ;
                }
        } 
        return l ;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr) ;
        int n = mountainArr.length() ;
        
        int st = 0 ;
        int end = peak ;
        while(st <= end){
            int mid = st + (end - st) / 2 ;
            if( mountainArr.get(mid) == target){
                return mid ;
            }else if(mountainArr.get(mid) > target){
                end = mid - 1 ;
            }else{
                st = mid + 1 ;
            }
        }
         st = peak + 1  ;
         end = n - 1 ;
        while(st <= end){
            int mid = st + (end - st) / 2 ;
            if( mountainArr.get(mid) == target){
                return mid ;
            }else if(mountainArr.get(mid) > target){
                
                st = mid + 1 ;
            }else{
                end = mid - 1 ;
            }
        }
        return -1 ;
    }
};