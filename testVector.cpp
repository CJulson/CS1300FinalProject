#include <iostream>
#include <vector>
using namespace std;

void sortScores(vector<int> &scores) {
    int temp;
    for(int i = 0; i < scores.size(); i++) {
        for(int j = 0; j < scores.size() - 1; j++) {
            if(scores.at(j) < scores.at(j+1)) {
                temp = scores.at(j+1);
                scores.at(j+1) = scores.at(j);
                scores.at(j) = temp;
            }
        }
    }
    return;
}

int main() {
    vector<int> nums = {1,4,2,3};
    sortScores(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums.at(i) << endl;
    }
}