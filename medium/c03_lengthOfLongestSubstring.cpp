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

int lengthOfLongestSubstring(string str)
{
	unsigned int max_ = 0;
	unsigned int j = 0, i = 0;
	unordered_set<char> set;
	for (i = 0; i < str.size(); ++i) {
		set.insert(str[i]);
		for (j = i+1; (j < str.size() && set.count(str[j]) != 1); ++j) {
			set.insert(str[j]);
		}
		max_ = max(max_, j - i);
		set.erase(str[i]);
	}
	return max_;
}

int main()
{
	string str = "abcabcbb";
	cout << lengthOfLongestSubstring(str) << endl;
	cout << endl;
    return 0;
}

