/*Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
Last Submission
Last Saved Code*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int i = BS(num);
        v.insert(v.begin() + i, num);
        /*
        for(auto x:v)
            cout<<x<<" ";
        cout<<endl;*/
    }
    
    double findMedian() {
        int s = v.size()-1;
        if(s<0)
            return 0;
        if(s%2==0)
            return v[s/2];
        else
            return double(v[s/2] + v[s/2+1])/2;
    }
private:
    vector<int> v;
    int BS(int num){
        int lo = 0;
        int hi = v.size()-1;
        int fl = 0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(v[mid]==num)
                return mid;
            if(v[mid]<num){
                lo = mid+1;
                fl = lo;
            }else{
                hi = mid-1;
            }
        }
        return fl;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
