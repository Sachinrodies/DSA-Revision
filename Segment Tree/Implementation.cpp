#include<iostream>
#include<vector>
using namespace std;
class SegmentTree{
    public:
        vector<int>seg;
        int n;
        SegmentTree(int n,vector<int>&arr){
            vector<int>seg(2*n);
            this->n=n;
            build(0,0,n-1,arr);
        }
        void build(int index,int low,int high,vector<int>&arr){
            if(low==high){
                seg[index]=arr[low];
                return ;
            }
            int mid=low+(high-low)/2;
            build(2*index+1,low,mid,arr);
            build(2*index+2,mid+1,high,arr);
            seg[index]=seg[2*index+1]+seg[2*index+2];
            //Time complexity O(n)
            
        }
        void update(int index,int low,int high,int i,int val){
            if(low==high){
                seg[index]=val;
                return ;
            }
            int mid=low+(high-low)/2;
            if(i<=mid){
                update(2*index+1,low,mid,i,val);
            }
            else{
                update(2*index+2,mid+1,high,i,val);
            }
            seg[index]=seg[2*index+1]+seg[2*index+2];
            //Time complexity O(logn)
        }
        int RangeSumQuery(int start,int end,int i,int low,int high){
            if(low>end|| high<start){
                return 0;
            }
            if(low>=start && high<=end){
                return seg[i];
            }
            int mid=start+(end-start)/2;
            int left=RangeSumQuery(start,end,2*i+1,low,mid);
            int right=RangeSumQuery(start,end,2*i+2,mid+1,high);
            return left+right;
            //Time complexity O(logn)
        }

};