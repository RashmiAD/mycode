/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int res = -1;
        int i = 0, j = dim[1] - 1;
        while(i < dim[0] && j >= 0) {
            if(binaryMatrix.get(i,j) == 1) {
                res = j;
                j--;
            }
            else {
                i++;
            }
        }
        
        return res;
    }
};
