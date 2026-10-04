class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0){
            return true;
        }
        for(int i = 0 ; i < flowerbed.size() ; i++){

            if(flowerbed[i] == 0){
                if(flowerbed.size() == 1 ){
                    flowerbed[i] = 1 ;
                   n-- ;
                }
               else if(i ==  0  && flowerbed[i + 1] == 0){
                   flowerbed[i] = 1 ;
                   n-- ;
                }

                else if (i == flowerbed.size() - 1 && flowerbed[i - 1] == 0){
                    flowerbed[i] = 1 ;
                    n-- ;
                }

                else if(i + 1 < flowerbed.size() && flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0){
                    flowerbed[i] = 1 ;
                    n-- ;
                }
            }
            if(n == 0){
                return true ;
            }
        }
        return false ;
    }
};