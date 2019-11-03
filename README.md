"# LeetCode" 
# 仓库说明
## 1.时间轴
|<center>时间</center>|<center>记录内容</center>|<center>备注</center>|
|:---|:---|:---|
|2019年9月29日10:12:19|开始着手刷题|起步|

## 2.内容描述
&emsp;&emsp;本仓库链接：https://github.com/guyongpu/LeetCode.git  
&emsp;&emsp;本仓库为LeetCode刷题记录，网址为：https://leetcode-cn.com/problemset/all/ ，[点击跳转到LeetCode中文题库](https://leetcode-cn.com/problemset/all/)
每个题的代码放在src中，在main.cpp设置number的值，numbers为题目编号，然后运行测试函数即可，例如需要运行题1时，在main.cpp中设置number=1即可:
~~~ c++
#include <iostream>

#include "src/P0000_ProblemHead.h"

using namespace std;

int main() {
    int number = 1;
    Test_Problem(number);
    cout << "Probelem " << number << " test finish!" << endl;
    return 0;
}
~~~

&emsp;&emsp;然后点击运行即可，题1结果如下：
~~~c++
2 4
Probelem 1 test finish!

Process finished with exit code 0
~~~

## 3.文件说明
|<center>文件名</center>|<center>内容描述</center>|
|:---|:---|
|P0000_CommonHead.h|用于声明一些公用的结构体或者函数，如树节点、链表节点等，在需要的时候引用.|
|P0000_ProblemHead.h|用于测试的头文件，则其中引入各个文件的头文件，用于创建各个问题的类.|
|P0000_ProblemHead.cpp|用于测试的源程序，在switch函数中创建并调用各个问题类的test()函数进行运行测试.|
|Pxxxx_*******.h|表示编号为xxxx问题的类的头文件.|
|Pxxxx_*******.cpp|表示编号为xxxx问题的类的头文件相对应的源程序.|

## 4.刷题日志
|<center>题号</center>|<center>题目名</center>|<center>完成日期</center>|<center>描述</center>|<center>备注</center>|
|:---:|:---:|:---:|:---|:---|
|P0001|两数之和|2019.9.29|描述：给定一个整数数组nums和target，求该数组中两个和为target的整数，返回下标.<br>思路：排序，然后使用双指针做法，最后计算下标.<br>复杂度：空间O(n),时间O(3n)|排序+首尾双指针|
|P0002|两数相加|2019.9.29|描述：两个非空的链表用来表示两个非负的整数，将这两个数相加起来，则会返回一个新的链表来表示它们的和.<br>思路：采用链表合并思想，1.当都不为空时，逐个合并；2.其中一个为空，则单独对另一个处理；3.最后处理carry可能存在的进位.<br>复杂度：空间O(max(N,M)),时间O(max(N,M))|链表合并思想+处理最后的carry|
|P0003|无重复字符的最长子串|2019.10.8|描述：给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度.<br>思路：使用滑动窗口来做，记录队列最长的值|还可以使用map进行优化|
|P0004|寻找两个有序数组的中位数|2019.10.10|描述：给定两个大小为m和n的有序数组nums1和nums2，找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n)).<br>思路：使用有序数组合并的思路，记录遍历的个数，当满足 cnt = mid 时，则说明已经遍历一半.|数组合并思路|
|P0005|最长回文子串|2019.10.14|描述：给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000.<br>思路：采用中心点扩展方法，遍历字符串，每次以(i,i)和(i,i+1)为中心点，遍历完后得到最长回文串,时间复杂度为 O(n^2).|需要掌握|
|P0006|Z字形变换|2019.10.14|描述：将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列.<br>思路：floor从1->numRows,然后numRows->1，遍历字符串，分别存入到每层的字符串中，最后拼接起来.|要仔细些.|
|P0007|整数反转|2019.10.14|描述：给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转.<br>思路：法1：int->string->反转->long long int->溢出判断->int; 法2：常规方法做，每次判断溢出.|两个方法要掌握.|
|P0008|字符串转换整数(atoi)|2019.10.14|描述：请你来实现一个 atoi 函数，使其能将字符串转换成整数.<br>思路：先找到开始字符，然后逐个转换，注意溢出的判断方法.|记住溢出判断方法.|
|P0009|回文数|2019.10.14|描述：判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数.<br>思路：法1：转化为字符串，然后判断是否回文;法2:计算一半数字,比较halfNum_l和halfNum_r.|掌握两种方法.|
|P0010|正则表达式匹配|2019.10.15|描述：给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配.<br>思路：使用递归回溯方法，但是需要进行剪枝，否则会超时.|时常复习，容易忘记.|
|P0011|盛最多水的容器|2019.10.14|描述：给定n个非负整数a1，a2，...，an，每个数代表坐标中的一个点(i, ai)，求容器可以容纳最多的水.<br>思路：法1：暴力法；法2：双指针法，较短的向较长的移动.|掌握双指针方法.|
|P0012|整数转罗马数字|2019.10.14|描述：给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内.<br>思路：法1：常规做法；法2：贪心算法.|掌握两种做法.|
|P0014|最长公共前缀|2019.10.14|描述：编写一个函数来查找字符串数组中的最长公共前缀，如果不存在公共前缀，返回空字符串 "".<br>思路：法1：先找最短字符串的长度,minLen，然后i->minLen,直到不相等，则[0,index]为最长;法2：找两两间的最长公共串，结束即得到结果.|两种方法都要会.|
|P0015|三数之和|2019.10.14|描述：给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素a，b，c ，使得a+b+c=0？找出所有满足条件且不重复的三元组.<br>思路：先确定一个数，后面的两个数采用双指针做法。第一个数要不与上一个相同，left也不能相同，这样可以避免查找去重.|注意查找去重会超时.|
|P0016|最接近的三数之和|2019.10.14|描述：给定一个包括n个整数的数组nums和一个目标值 target。找出nums中的三个整数，使得它们的和与 target 最接近.<br>思路：套用三个数相加的思路，不过要注意找绝对值最小的.|left要从i+1开始.|
|P0017|电话号码的字母组合|2019.10.14|描述：给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合.<br>思路：使用递归方法，每遇到一个字符，则拼接该字符的所有情况，然后递归下一个字符.|注意复习.|
|P0018|四数之和|2019.10.14|描述：给定一个包含n个整数的数组nums和一个目标值 target，判断nums中是否存在四个元素 a，b，c和d ，使得a+b+c+d的值与target相等？找出所有满足条件且不重复的四元组.<br>思路：两重循环+双指针做法，即在三数之和的基础上再加上一次循环，每次循环保证不重复.|注意去重.|
|P0019|删除链表的倒数第N个节点|2019.10.15|描述：给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点.<br>思路：用双指针实现，pLast指针先走n步，然后pFront再一起走，直到pLast.next=nullptr,另外注意删除头节点的处理.|双指针+头节点处理.|
|P0020|有效的括号|2019.10.16|描述：给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效.<br>思路：将左括号放入栈中，遇到右括号时出栈，然后进行匹配.|常见题.|
|P0021|合并两个有序链表|2019.10.16|描述：将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的.<br>思路：每次选择较小的链表头进行匹配.|常见题.|
|P0022|括号生成|2019.10.21|描述：给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合.<br>思路：递归，当open数量小于n的数量，则加一个open，close数量小于open的数量，则加一个close.|掌握递归方法.|
|P0023|合并K个排序链表|2019.10.21|描述：合并 k 个排序链表，返回合并后的排序链表.<br>思路：每次找最小节点，然后连接到新链表上.1.判空;2.最小节点;3.指针下移;4.接到新链表.时间O(kn)/空间O(1).|使用vector,再sort排序,但复杂度较高.|
|P0024|两两交换链表中的节点|2019.10.18|描述：给定一个链表，两两交换其中相邻的节点，并返回交换后的链表.<br>思路：每次取两个节点进行交换，使后节点->前节点，并将前节点->tail.|要仔细.|
|P0025|K个一组翻转链表|2019.10.17|描述：给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表.<br>思路：分两步处理，先翻转第一段，确定头，然后再翻转剩余的部分.将每段翻转后的头连接到上一段的尾节点上.|本身不难，但是需要十分地仔细.|
|P0026|删除排序数组中的重复项|2019.10.17|描述：给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度.<br>思路：用双指针方法，法1：删除重复元素；法2：覆盖重复元素的值.|法2的思路要掌握，时间复杂度更低.|
|P0027|移除元素|2019.10.18|描述：给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度.<br>思路：用双指针做法，一个指针用做遍历指针i，另一个用作实际元素下标index，当不相等时index++,遍历结束index为长度.|双指针做法.|
|P0028|实现strStr()|2019.10.20|描述：现 strStr()函数。给定一个haystack字符串和一个needle字符串，在haystack 字符串中找出needle字符串出现的第一个位置(从0开始)。如果不存在，则返回-1.<br>思路：法1：暴力法BF，双重循环求解；法2：KMP算法，(1)计算next数组;(2)右移next数组;(3)字符串匹配.|KMP计算next数组是重点（常规/进阶）.|
|P0029|两数相除|2019.10.20|描述：给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符.<br>思路：法1：不断减除数，但会超时；2.位移代替除法，（1）处理好被除数=INT_MIN，单独做一次减法；（2）不能直接写result_1+result_2>INT_MAX，会溢出.|掌握用位移代替除法，以及result>INT_MAX可能会溢出.|
|P0030|串联所有单词的子串|2019.10.22|描述：给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置.<br>思路：法1：滑动窗口+hashmap方法，当count=word_num时，成功.法2：计算words的字符串所有排列组合，然后查找，但是会超时.|主要掌握法1.|
|P0031|下一个排列|2019.10.22|描述：实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列.<br>思路：分三个步骤,(1)找一组数nums[i-1]<nums[i];(2)找到nums[i-1]<nums[j],进行交换;(3)翻转nums[i-1]之后的序列.|这个题要掌握做法.|
|P0032|最长有效括号|2019.10.23|描述：给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度.<br>思路：方法1.使用动态规划;方法2.使用暴力求解;方法3.使用栈(保存下标)求解.|重点掌握第2和第3种.|
|P0033|搜索旋转排序数组|2019.10.23|描述：搜索一个给定的目标值，如果旋转数组中存在这个目标值，则返回它的索引，否则返回-1.<br>思路：二分查找思想，先nums[left]与nums[mid]比较，确定mid前后位置，然后缩小区间.|无重复元素,重要题目.|
|P0034|在排序数组中查找元素的第一个和最后一个位置|2019.10.23|描述：给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置，要求O(log n).<br>思路：方法1：直接遍历;2.二分查找+左右遍历;3.二分查找+二分查找左下标+二分查找右下标.|方法1,2会超时，掌握方法3.|
|P0035|搜索插入位置|2019.10.23|描述：给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置.<br>思路：先处理一些特殊情况，然后套用二分查找模板进行计算.最后比较nums[mid]的关系，返回正确的下标.|返回下标要仔细.|
|P0036|有效的数独|2019.10.24|描述：判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可.<br>思路：方法1.使用三次遍历进行判断行/列/方格是否有效;方法2.使用一次遍历+3个hashmap容器判断.|掌握方法2.|
|P0037|解数独|2019.10.25|描述：编写一个程序，通过已填充的空格来解决数独问题.<br>思路：在P0036的基础上做，rowsMap,colsMap,boxsMap,最后用上DFS算法进行求解.|DFS重要题目.|
|P0038|报数|2019.10.25|描述：给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项.<br>思路：当前数的结果基于前一个数的结果，不断递推.如4:1211，1个1,1个2,2个1，得到5:111221.|正常解法就行.|
|P0039|组合总和|2019.10.26|描述：给定一个无重复元素的数组 candidates和一个目标数target，找出candidates中所有可以使数字和为target的组合，数字可以重复出现.<br>思路：采用DFS做，记录路径record，符合要求时将record加入result中，然后继续DFS.|重要题，掌握DFS.|
|P0040|组合总和II|2019.10.26|描述：给定一个数组candidates 和一个目标数 target ，找出candidates中所有可以使数字和为 target 的组合，每个组合中每个数字只用一次.<br>思路：在P0039的基础上，加上两个去重条件，(1)在从start开始时，如果candidates[i-1] = candidates[i]，则不进行计算;（2）下一次从i+1开始.|也可以使用hashmap实现.|
|P0041|缺失的第一个正数|2019.10.26|描述：给定一个未排序的整数数组，找出其中没有出现的最小的正整数.<br>思路：利用桶排序思想，将[1,len]范围内的数x放到num[x-1]的位置上，最后遍历nums，如果nums[i]!=i+1,则返回i+1.|桶排序思想.|
|P0042|接雨水|2019.10.26|描述：给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水.<br>思路：方法1-2.计算每个高度的存水量，累加;方法3-5.计算每个柱子的存水量，其中方法5采用双指针法，效率最高.|掌握5种方法.|
|P0043|字符串相乘|2019.10.26|描述：给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式.<br>思路：num1中每一位乘以nums，然后将结果进行累加，实现一个字符串相加的函数即可.|需要仔细些.|
|P0044|通配符匹配|2019.10.27|描述：给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配.<br>思路：回溯法（超时）或者动态规划方法。遇到？，直接匹配；如果遇到*，则考虑匹配0个，1个，多个.|掌握递归回溯和动态规划.|
|P0045|跳跃游戏II|2019.10.30|描述：给定一个非负整数数组，你最初位于数组的第一个位置，数组中的每个元素代表可以跳跃的最大长度，使用最少的跳跃次数到达数组的最后一个位置.<br>思路：方法1：从前往后找，在每跳的范围内找能到的下一跳最大位置，不断更新；方法2：从后往前，每次找第一个能到达endPos的下标，知道nums[0]>=endPos.|掌握两种方法，方法2会超时.|
|P0046|全排列|2019.10.31|描述：给定一个没有重复数字的序列，返回其所有可能的全排列.<br>思路：确定begin位置，然后将[begin,len-1]的元素与nums[begin]交换，递归，当begin=len-1，则得到一个结果.|元素各不相同，不需要考虑去重.|
|P0047|全排列II|2019.10.31|描述：给定一个可包含重复数字的序列，返回所有不重复的全排列.<br>思路：方法1：直接find去重；方法2：在普通全排列的基础上增加isRepeat检测[begin,i)之间是否存在nums[index]，存在则跳过.其他不变.|掌握方法1和方法2.|
|P0048|旋转图像|2019.10.31|描述：给定一个 n × n 的二维矩阵表示一个图像，将图像顺时针旋转 90 度.<br>思路：方法1：借用额外数组;方法2：分三步实现；方法3：每次旋转一圈.|掌握三种方法.|
|P0049|字母异位词分组|2019.10.31|描述：给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串.<br>思路：将每个字符串排序放到map<string,int>，int为result中的下标+1，如果重复出现，则放到result中.|比较好做的题.|
|P0050|Pow(x,n)|2019.10.31|描述：实现 pow(x, n) ，即计算 x 的 n 次幂函数.<br>思路：递归二分法计算，n为奇数时，half*half;偶数时，half*half*x.|掌握暴力法和递归二分法.|
|P0054|旋转矩阵|2019.11.3|描述：给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素.<br>思路：定位[pos1_row,pos1_col]和[pos2_row,pos2_col]，然后遍历一圈，当pos1_row=pos2_row或pos1_row=pos2_row时，结束循环，再进行截取.|掌握定位点和循环结束条件，已经最后的截取.|
|P0055|跳跃游戏|2019.10.30|描述：给定一个非负整数数组，你最初位于数组的第一个位置，数组中的每个元素代表你在该位置可以跳跃的最大长度，判断你是否能够到达最后一个位置.<br>思路：方法1：回溯，不断回溯，直到走到nums.size()-1；方法2：贪心，不断更新nums[0]能到达的最大位置.|使用贪心算法或者递归回溯.|
|P0081|搜索旋转排序数组II|2019.10.13|描述：判断给定的目标值是否存在于旋转数组中.<br>思路：套用旋转数组的解法，先判断nums[mid]的位置，然后再进一步比较nums[left]与target，不断缩小范围.|需要更加仔细处理|
|P0121|买卖股票的最佳时机|2019.11.1|描述：给定一个数组，它的第i个元素是一支给定股票第i天的价格。如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润.<br>思路：方法1.遍历数组，记录当前为止的最小值，然后第二次遍历计算最大利益，也可以优化为一次遍历；方法2.暴力求解.|方法2接近动态规划思想.|
|P0122|买卖股票的最佳时机II|2019.11.1|描述：给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格.设计一个算法来计算你所能获取的最大利润.<br>思路：计算差值，将所有差值为正表示能够获得收益，加差值为正的值累加.|其实也可以优化为一次遍历.|
|P0123|买卖股票的最佳时机III|2019.11.1|描述：给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你最多可以完成两笔交易.<br>思路：方法1：遍历一次，记录minLeft和maxRight，然后遍历更新result；方法2：先暴力法确定两个点，然后再遍历剩余数据；方法3:暴力法解决.|掌握方法1、2、3.|
|P0136|只出现一次的数字|2019.10.13|描述：给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素.<br>思路：两个相同的数异或等于0，因此将所有数进行异或，最后得到的数就是只出现一次的数.|常见面试题|
|P0137|只出现一次的数字II|2019.10.13|描述：给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素.<br>思路：采用二进制做法，计算每一位的累加和，如果是K的倍数，则改为为0；否则为1.|记住通用解法|
|P0146|LRU缓存机制|2019.9.29|描述：运用你所掌握的数据结构，设计和实现一个LRU(最近最少使用)缓存机制。它应该支持以下操作：获取数据get和写入数据put.<br>思路：使用哈希表和双向链表实现.|多复习|
|P0147|对链表进行插入排序|2019.9.30|描述：按照插入排序的思想，对链表进行插入排序.<br>思路：在进行插入排序的时候，对当前待处理节点要保留 NodeFront、NodeCurrent、NodeNext三个节点，对于比较节点要保留 pNode0 和 pNode。|面试题，要复习|
|P0148|排序链表|2019.10.8|描述：在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序.<br>思路：对链表进行快速排序或归并排序进行实现均可，和普通的数组排序有所不同，要注意区分.|该题比较重要，要注意复习|
|P0149|直线上最多的点|2019.10.8|描述：给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上.<br>思路：对每个点进行计算通过第i个点的点的数量，对于每一个点，将斜率的分子分母约分后存储到map中.|重合的点不用计算，直接+1就行.|
|P0150|逆波兰表达式求值|2019.10.8|描述：根据逆波兰表示法，求表达式的值。有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式.<br>思路：构造一个stack<int>numbers用于存放计算结果，每次遇到运算符则弹出两个元素计算，并把结果存入到numbers中.|题目不难，记得思路即可.|
|P0151|翻转字符串里的单词|2019.10.8|描述：给定一个字符串，逐个翻转字符串中的每个单词.<br>思路：运用公式 BA = （A^T B^T)^T，先对每个单词翻转，然后再整个字符串翻转。最后去除多余空格，去除首尾空格，及处理特殊字符串.|题目本身不难，但是在处理空格时要仔细.|
|P0152|乘积最大子序列|2019.10.9|描述：给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）.<br>思路：令imax为当前最大值，imax = max(imax * nums[i], nums[i])，负数会导致大变小，小变大，故需要维护当前最小值，当负数出现时imax与imin交换再进行下一步计算.|需要复习|
|P0153|寻找旋转排序数组中的最小值|2019.10.10|描述：假设按照升序排序的数组在预先未知的某个点上进行了旋转，请找出其中最小的元素.<br>思路：此题是剑指Offer上原题，采用二分查找的思想做，每次用 num[start]与num[mid]比较，最终start指向最大元素，last指向最小元素.|注意循环条件|
|P0154|寻找旋转排序数组中的最小值II|2019.10.10|描述：假设按照升序排序的数组在预先未知的某个点上进行了旋转，请找出其中最小的元素，注意数组中可能存在重复的元素.<br>思路：在二分查找的思路下，考虑重复元素的情况，如果遇到相等情况，无法判断mid处的位置，只能在[start , last]之间遍历查找.|考虑重复元素|
|P0155|最小栈|2019.10.10|描述：设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈.<br>思路：法1：使用辅助栈，相等时要一起push和pop；法2：只用一个栈，栈顶第一个为最小数据。第二个为实际的数据.|两种方法均须掌握|
|P0156|加锁题|-|-|-|
|P0157|加锁题|-|-|-|
|P0158|加锁题|-|-|-|
|P0159|加锁题|-|-|-|
|P0160|相交链表|2019.10.11|描述：先判断两个链表的长度，然后长的先走几步，接着一起走，第一次相遇就是相交的起始节点.<br>思路：找到两个单链表相交的起始节点.|常见题|
|P0161|加锁题|-|-|-|
|P0162|寻找峰值|2019.10.11|描述：峰值元素是指其值大于左右相邻值的元素,输入数组nums，相邻元素不相等，找到峰值元素并返回其索引,要求时间复杂度O(logN).<br>思路：使用二分查找，不断比较nums[mid]与nums[mid + 1]，直到循环结束.|此题要复习|
|P0163|加锁题|-|-|-|
|P0164|最大间距|2019.10.13|描述：给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值，如果数组元素个数小于 2，则返回 0.<br>思路：排序+线性复杂度，则用桶排序思想，桶容量=(max-min)/len+1, 桶数量 = (max-min)/桶容量 +1.|桶排序思想，要复习|
|P0165|比较版本号|2019.10.13|描述：比较两个版本号 version1 和 version2.<br>思路：切割出整数，然后比较.|常见题|
|P0166|分数到小数|2019.10.13|描述：给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。如果小数部分为循环小数，则将循环的部分括在括号内.<br>思路：先计算整数部分，然后将每次的被除数保存，知道出现重复，则说明找到循环节[pos,strNum.size-1]，否则是有限小数.|分数的小数部分一定是有限或者循环的.|
|P0167|两数之和II-输入有序数组|2019.10.14|描述：给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数，返回下标.<br>思路：使用双指针方法，left从最左，right从最右，逐渐向中间逼近.|注意题目要求下标+1.|
|P0168|Excel表列名称|2019.10.14|描述：给定一个正整数，返回它在 Excel 表中相对应的列名称.<br>思路：26进制转换，难点在于余数=0时要向商借1位，否则会出错.|记住难点的处理方法.|
|P0169|求众数|2019.10.14|描述：给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素.<br>思路：使用士兵攻城思想，设置计数器，相同的时候cnt+1，不同则cnt-1，当cnt=0,则设置nums[i]为新的士兵，最后的士兵就是众数.|求出现次数超过一半的数.|
|P0170|加锁题|-|-|-|
|P0171|Excel表列序号|2019.10.14|描述：给定一个Excel表格中的列名称，返回其相应的列序号.<br>思路：26进制转10进制.|此题与169相似|
|P0172|阶乘后的零|2019.10.14|描述：给定一个整数 n，返回 n! 结果尾数中零的数量.<br>思路：2的个数比5多，所以只要考虑5的个数.用层数的思想，累加每一层5的个数.|比较重要的题|
|P0173|二叉搜索树迭代器|2019.10.16|描述：实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器.<br>思路：使用栈实现二叉树的中序遍历.|重点题，要复习|
|P0175|Mysql题目|-|-|-|
|P0176|Mysql题目|-|-|-|
|P0177|Mysql题目|-|-|-|
|P0178|Mysql题目|-|-|-|
|P0179|最大数|2019.10.21|描述：给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数.<br>思路：排序，return ab > ba,然后连接.最后判断str[0]是否为0，是则返回0.|注意处理0|
|P0180|Mysql题目|-|-|-|
|P0181|Mysql题目|-|-|-|
|P0182|Mysql题目|-|-|-|
|P0183|Mysql题目|-|-|-|
|P0184|Mysql题目|-|-|-|
|P0185|Mysql题目|-|-|-|
|P0186|加锁题|-|-|-|
|P0187|重复的DNA序列|2019.10.21|描述：编写一个函数来查找 DNA 分子中所有出现超过一次的10个字母长的序列(子串).<br>思路：遍历字符串，每10个一组，存入到hashmap中，记录出现的次数.|题目不难.|
|P0189|旋转数组|2019.10.23|描述：给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数.<br>思路：方法1.每次旋转一位；方法2.翻转思想,BA = (B^T+A^T)^T|重点掌握翻转思想|
|P0190|颠倒二进制位|2019.10.24|描述：颠倒给定的 32 位无符号整数的二进制位.<br>思路：进行32次循环，获取每一位的值，然后进行加法或者位运算，给result的每一位赋值.|掌握方法1(加法计算)和方法2(位运算)|
|P0191|位1的个数|2019.10.24|描述：编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数.<br>思路：方法1：进行32次循环，计算每位的情况;2.使用n=n&(n-1)，减少循环次数.|掌握两种方法|
|P0192|Bash题目|-|-|-|
|P0193|Bash题目|-|-|-|
|P0194|Bash题目|-|-|-|
|P0195|Bash题目|-|-|-|
|P0196|Mysql题目|-|-|-|
|P0197|Mysql题目|-|-|-|
|P0198|打家劫舍|2019.10.24|描述：给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额.<br>思路：方法1.动态规划dp[n] = MAX(dp[n-1], dp[n-2]+num);方法2.奇偶数之和，每次进行处理最优解.|掌握动态规划和奇偶数求和的方法|
|P0199|二叉树的右视图|2019.10.24|描述：给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值.<br>思路：采用层序遍历思想，把每层的最右节点保存到result中即可.|掌握层序遍历|
|P0200|岛屿数量|2019.10.24|描述：给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量.<br>思路：使用一个graphFlag标记数组，将陆地进行标记，并递归标记其相邻的所有岛屿.|深度优先搜索+递归标记|
|P0201|数字范围按位与|2019.10.24|描述：给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含m, n两端点）.<br>思路：方法1.从高位开始，第i位相同，则累加，不同则停止;方法2.不断右移，直到m=n，然后再在后面补0.|掌握方法1和方法3|
|P0202|快乐数|2019.10.25|描述：编写一个算法来判断一个数是不是“快乐数”，即讲各个位上的平方累加，最终和为1.<br>思路：如果累加和重复出现，则说明不是快乐数，直接用hashmap判断是否重复即可.|hashmap判断是否重复|
|P0203|移除链表元素|2019.10.25|描述：删除链表中等于给定值 val 的所有节点.<br>思路：方法1.创建一个虚拟头节点，并不断连接不为val的节点，注意要给new_pNode->next = nullptr；方法2.不创建头节点，其他与法1类似；方法3.存入vector中，再连接.|掌握三种方法|
|P0204|计数质数|2019.10.25|描述：统计所有小于非负整数 n 的质数的数量.<br>思路：使用bool标记数组，然后进行筛法计数.|重要题目|
|P0205|同构字符串|2019.10.25|描述：给定两个字符串 s 和 t，判断它们是否是同构的，如add与egg.<br>思路：方法1.构建sTOt和tTOs的映射，检测是否存在一对多情况；方法2.计算字符首次出现的下标，如序列相等，则满足.|掌握方法1和方法2|
|P0206|反转链表|2019.10.25|描述：反转一个单链表.<br>思路：定义nodePrev,nodeCurr,nodeNext，每次将nodeCurr->nodePrev，遍历链表，nodePrev为新头节点.|重要的题目|
|P0207|课程表|2019.10.25|描述：给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习，即拓扑是否有环.<br>思路：方法1.拓扑排序思想，每次找入度为0的节点;方法2.BFS，借助队列实现拓扑排序;方法3.DFS，深度搜索，如果重复访问，则说明成环.|掌握三种方法|
|P0208|实现trie(前缀树)|2019.10.27|描述：实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作.<br>思路：定义*tries[MAXN]和is_str变量，不断遍历，遇到不存在的节点是创建新节点，单词结束的节点is_str=true.|重要题目，一定要会手写.|
|P0209|长度最小的子数组|2019.10.27|描述：给定一个含有n个正整数的数组和一个正整数s找出该数组中满足其和≥ s的长度最小的连续子数组.如果不存在符合条件的连续子数组，返回0.<br>思路：采用滑动窗口的做法，start和end指针，当windSum>=s，则start后移；否则end后移，当windSum>=s时，计算result=min(result,end-start+1).|重掌握滑动窗口做法.|
|P0210|课程表II|2019.11.1|描述：给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序.<br>思路：每次找入度为0的节点，直到所有全部找完，如果还剩下课程没有处理，则说明不能完成，否则翻转后返回result.|也可以采用BFS或DFS.|
|P0211|添加与搜索单词-数据结构设计|2019.11.1|描述：设计一个支持addWord和search两种操作的数据结构，可以搜索文字或正则表达式字符串.<br>思路：使用map<int,vector<string>>，长度为key，将长度相同的字符串放在一个vector中，然后查找.|长度hashmap字典或者前缀树都可以.|
|P0217|存在重复元素|2019.10.28|描述：给定一个整数数组，判断是否存在重复元素，如果任何值在数组中出现至少两次,函数返回true,如果数组中每个元素都不相同，则返回false.<br>思路：方法1.检测任意两个元素是否重复O,复杂度(n^2)；方法2.排序再遍历是否相邻相等,复杂度(nlogn)；方法3.采用hashmap方法,复杂度(n).|掌握三种方法.|
|P0219|存在重复元素II|2019.10.28|描述：给定一个整数数组和一个整数k，判断数组中是否存在两个不同的索引i和j，使得nums[i]=nums[j]，并且i和j的差的绝对值最大为k.<br>思路：滑动窗口思想，要求(j-i)<=k,因此维护一个k+1大小的滑动窗口，判断nums[i]是否存在与当前滑动窗口内，存在则返回true.|窗口大小为k+1，当size=k+1时，先删除nums[i-k-1]，再判断是否重复.|
|P0220|存在重复元素III|2019.10.28|描述：给定一个整数数组，判断数组中是否有两个不同的索引i和j，使得 nums[i]和nums[j]的差的绝对值最大为t，并且i和j之间的差的绝对值最大为k.<br>思路：滑采用暴力法的滑动窗口会超时，因此采用二叉搜索树思想用set解决，num_double-t <= x，寻找第一个大于等于num_double-t的元素计算.|掌握暴力法和二叉树搜索树set方法.|
|P0260|只出现一次的数字III|2019.10.13|描述：给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。找出只出现一次的那两个元素.<br>思路：将所有数字进行异或得到res，找到res中为1的位index，则num1在第index位为1，num2在第index位为0，分两类异或，得到结果.|系列I、II、III都要掌握.|
