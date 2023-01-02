#include <iostream>
#include <vector>

using namespace std;

vector<int> collatzSequence(int n){
    vector<int> sequence;
    sequence.push_back(n);
    while (n!=1){
        if(n==1){
            break;
        }
        if(n%2){
            n *= 3;
            n += 1;
            sequence.push_back(n);
        }
        else{
            n /= 2;
            sequence.push_back(n);
        }
    }
    return sequence;
}

vector<int> shortestCollatzSequence(int start, int end){
    int min = INT32_MAX;
    vector<int> min_sequence;
    vector<int> temp;
    for(int i=start; i<=end; i++){
        temp.clear();
        temp = collatzSequence(i);
        if(temp.size() < min){
            min_sequence = temp;
            min = temp.size();
        }
    }
    return min_sequence;
}

vector<int> longestCollatzSequence(int start, int end){
    int max = 0;
    vector<int> max_sequence;
    vector<int> temp;
    for(int i=start; i<=end; i++){
        temp.clear();
        temp  = collatzSequence(i);
        if(temp.size() >= max){
            max_sequence = temp;
            max = temp.size();
        }
    }
    return max_sequence;
}

int main(void){
    vector<int> answer1 = shortestCollatzSequence(100,1000);

    for(int i=0; i<answer1.size(); i++){
        cout<<answer1[i]<<" ";
    }
    cout<<endl<<answer1.size()<<endl;

    vector<int> answer2 = longestCollatzSequence(90000,99999);
    for(int i=0; i<answer2.size(); i++){
        cout<<answer2[i]<<" ";
    }
    cout<<endl<<answer2.size()<<endl;

    vector<int> temp = collatzSequence(128);

    return 0;
}