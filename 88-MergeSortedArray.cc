/**
 * Leetcode 88 Merge Sorted Array
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as 
 * one sorted array.
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal 
 * to m + n) to hold additional elements from nums2. The number of elements 
 * initialized in nums1 and nums2 are m and n respectively.
 */
 
 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 
 class Solution {
 public:
     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         for(int i = m;i < m + n;i++) {
             nums1[i] = nums2[i - m];
         }
         sort(nums1.begin(), nums1.end());
     }
 };

