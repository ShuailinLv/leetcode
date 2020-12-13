/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

 示例 1:

 输入: s = "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 示例 2:

 输入: s = "bbbbb"
 输出: 1
 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 示例 3:

 输入: s = "pwwkew"
 输出: 3
 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
	  示例 4:

	  输入: s = ""
	  输出: 0
	   

	   提示：

	   0 <= s.length <= 5 * 104
	   s 由英文字母、数字、符号和空格组成
*/

#include <iostream>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>
#include <Windows.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
	// sliding window
	unordered_set<char> occ;
	int n = s.size();
	int rk = -1, ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i != 0) {
			occ.erase(s[i - 1]);
		}
		while (rk + 1 < n && !occ.count(s[rk + 1])) {  // .count always returns 0 or 1
			occ.insert(s[rk + 1]);
			++rk;
		}
		ans = max(ans, rk - i + 1);
	}
	return ans;
}


int main()
{
	string str = "abcabcbb";
	cout << lengthOfLongestSubstring(str) << endl;
	cout << endl;
    return 0;
}

