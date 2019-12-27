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
|P0051|N皇后|2019.11.6|描述：n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击.<br>思路：采用数独的思想，使用map数组来记录是否行列存在重复，通过x+y和x-y的值记录斜率为1和-1，每次填写1列，尝试0->n-1行.|方法1为原始写法，方法2进行了优化和规范.|
|P0052|N皇后II|2019.11.6|描述：n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击.<br>思路：采用数独的思想，使用map数组来记录是否行列存在重复，通过x+y和x-y的值记录斜率为1和-1，每次填写1列，尝试0->n-1行,与51题一样.|最后直接返回结果个数.|
|P0053|最大子序和|2019.11.3|描述：给定一个整数数组 nums，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和.<br>思路：遍历数组nums，当temp_sum<0时，更新temp_sum；当temp_sum>=0时，则累加，并更新sum.|掌握方法1和2，还有暴力法也可以.|
|P0054|旋转矩阵|2019.11.3|描述：给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素.<br>思路：定位[pos1_row,pos1_col]和[pos2_row,pos2_col]，然后遍历一圈，当pos1_row=pos2_row或pos1_row=pos2_row时，结束循环，再进行截取.|掌握定位点和循环结束条件，已经最后的截取.|
|P0055|跳跃游戏|2019.10.30|描述：给定一个非负整数数组，你最初位于数组的第一个位置，数组中的每个元素代表你在该位置可以跳跃的最大长度，判断你是否能够到达最后一个位置.<br>思路：方法1：回溯，不断回溯，直到走到nums.size()-1；方法2：贪心，不断更新nums[0]能到达的最大位置.|使用贪心算法或者递归回溯.|
|P0056|合并区间|2019.11.4|描述：给出一个区间的集合，请合并所有重叠的区间.<br>思路：先排序，然后遍历区间，不断合并区间，无法合并时保存结果.|掌握方法.|
|P0057|插入区间|2019.11.4|描述：给出一个无重叠的 ，按照区间起始端点排序的区间列表，必要时合并区间.<br>思路：方法1.直接加入区间，然后排序合并；方法2.找到新区间的位置，分3种情况，然后再合并，本题采用方法2.|方法2分情况要仔细.|
|P0058|最后一个单词的长度|2019.11.4|描述：给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度.<br>思路：方法1：去重空格得到str，然后计算；方法2：计算start和end，然后计算end-start.|掌握方法1和方法2.|
|P0059|螺旋矩阵II|2019.11.4|描述：给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵.<br>思路：安装遍历的思路给每个坐标赋值即可.|掌握遍历结束条件.|
|P0060|第K个排列|2019.11.4|描述：给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列，输出第K个排列.<br>思路：找规律，ans=ans+nums[(k-1)/arr[n]],进行n次计算即可得到结果.|要复习这个题.|
|P0061|旋转链表|2019.11.5|描述：给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数.<br>思路：方法1. 将BA = AB中将B尾指针与A的头指针连接；方法2.采用BA = (A^T  B^T)^T的方法.|优先采用方法1，方法2更适用于数组旋转操作.|
|P0062|不同路径|2019.11.5|描述：一个机器人位于一个 m x n 网格的左上角（0,0),机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角(n-1,m-1),问总共有多少条不同的路径.<br>思路：方法1.动态规划，dp[i][j]是到达 i, j 最多路径，则dp[i][j] = dp[i-1][j] + dp[i][j-1]；方法2.递归方法，会超时.|掌握方法1和方法2.|
|P0063|不同路径II|2019.11.5|描述：一个机器人位于一个 m x n 网格的左上角，走到右下角，有多少种不同的路径，图中1表示障碍物.<br>思路：方法1；dp[i][j] = dp[i - 1][j] + dp[i][j - 1];方法2.采用递归回溯，但是会超时.|初始化时dp[0][j]和dp[i][0]要注意，另外起点/终点为1，返回0.|
|P0064|最小路径和|2019.11.7|描述：给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小，每次只能向下或者向右移动一步.<br>思路：和62,63的思路类似，采用动态规划，dp[i][j]= min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];即为到(i,j)的最小路径和.|掌握动态规划.|
|P0065|有效数字|2019.11.7|描述：验证给定的字符串是否可以解释为十进制数字.<br>思路：将字符串按照e进行分段，e前面为整数/小数，e后面为整数，然后分别判断是否有效..|要仔细处理.|
|P0066|加一|2019.11.7|描述：给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一.<br>思路：设置carry=1，sum = digits[i]+carry;当carry=0时直接终止，最后carry=1，则要在digits前插入1.|在digits原地上修改，空间复杂度O(1).|
|P0067|二进制求和|2019.11.7|描述：给定两个二进制字符串，返回他们的和（用二进制表示）.<br>思路：使用链表合并的思路，while(i>=0 && j >=0),最后处理进位+翻转字符串即可.|链表合并的思想.|
|P0068|文本左右对齐|2019.11.8|描述：给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本.<br>思路：题目不难，按照整个的思路处理即可，唯一需要注意的是i<=len,目的是最后一个单词进行处理，同时处理完后要i=i-1.|编码仔细些.|
|P0069|x的平方根|2019.11.8|描述：实现int sqrt(int x)函数，返回整数部分.<br>思路：方法1.二分法，注意mid=low+(high-low)/2，否则会溢出；方法2.暴力法.|掌握方法2.|
|P0070|爬楼梯|2019.11.8|描述：假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？<br>思路：先根据/分隔字符，然后遍历，遇到.回退1；遇到..，回退2。最后拼接路径即可.|用vector删除效率较低，用stack会好一些.|
|P0071|简化路径|2019.11.8|描述：以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径.<br>思路：F(n)=F(n-1)+F(n-2)，方法1：直接循环，temp1记录F(n-1),temp2记录F(n-2)；方法2：采用递归遍历.|递归会超时，采用直接循环.|
|P0072|编辑距离|2019.11.9|描述：给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数.<br>思路：使用动态规划，dp[i][j]=1+min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]).|掌握动态转化方程.|
|P0073|矩阵置零|2019.11.9|描述：给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法.<br>思路：先将0的行列号用map记录，第二次遍历时进行修改.|也可以不用额外空间，比如遍历第i行时对第i-1行置零，使得一次遍历完成置零.|
|P0074|搜索二维矩阵|2019.11.9|描述：编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值.<br>思路：方法1.使用2次二分查找，1次先确定所在行，另1次在行中查找是否存在数据；方法2.将矩阵映射为一条长链表，然后直接二分查找.|掌握方法1和2.|
|P0075|颜色分类|2019.11.9|描述：给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列.<br>思路：沿着数组移动 curr 指针，若nums[curr] = 0，则将其与 nums[p0]互换；若 nums[curr] = 2 ，则与 nums[p2]互换.|双指针+交换.|
|P0076|最小覆盖字串|2019.11.10|描述：给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串.<br>思路：用3个map，map_win，map_t，map_s,使用滑动窗口做法，end用于扩展，start用于缩小窗口.|滑动窗口.|
|P0077|组合|2019.11.10|描述：给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合.<br>思路：使用dfs实现，每次添加一个数i，下一次从i+1开始，但需要进行剪枝，否则时间复杂度较高.|理解剪枝方法.|
|P0078|子集|2019.11.10|描述：给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）.<br>思路：本题与77题做法相同，注意剪枝，对每种长度的情况进行考虑，然后DFS.|DFS遍历+剪枝.|
|P0079|单词搜索|2019.11.10|描述：给定一个二维网格和一个单词，找出该单词是否存在于网格中.<br>思路：从每个点作为起点进行dfs，然后按常规思路进行DFS搜索，即可得到答案.|深度优先.|
|P0080|删除排序数组中的重复项II|2019.11.11|描述：给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度.<br>思路：采用一个index作为实际下标，另一个为遍历下标，然后后面的值覆盖前面的.|双指针做法.|
|P0081|搜索旋转排序数组II|2019.10.13|描述：判断给定的目标值是否存在于旋转数组中.<br>思路：套用旋转数组的解法，先判断nums[mid]的位置，然后再进一步比较nums[left]与target，不断缩小范围.|需要更加仔细处理|
|P0082|删除排序链表中的重复元素II|2019.11.11|描述：给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现的数字.<br>思路：使用三个指针，pPrev指向不重复的节点，pCurr指向当前待比较节点，pNode指向遍历节点，设置dupFlag标记，同时处理最后的dupFlag.|连接时要将pPrev->next置空|
|P0083|删除排序链表中的重复元素|2019.11.11|描述：给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次.<br>思路：使用两个指针，pCurr指向当前新链表的最后一个节点，pNode为遍历节点，记得pCurr->next置空.|双指针法|
|P0084|柱状图中最大的矩形|2019.11.11|描述：给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1.<br>思路：计算每个高度往两边扩展的最大宽度，然后计算矩形面积，取最大值.|进行一定程度的剪枝|
|P0085|最大矩形|2019.11.11|描述：给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积.<br>思路：动态规划，dp[i][j] = {向左，向上，面积},本质上是将每个点作为矩形的右下角，然后寻找能构造出的最大面积.|记住计算temp_area的原理|
|P0086|分隔链表|2019.11.12|描述：给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前.<br>思路：建立两个链表头sml和big，将原链表小于x与大于等于x的两类节点分别连接到sml和big上，再连接sml和big即可.|双指针法|
|P0087|扰乱字符串|2019.11.12|描述：给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树.<br>思路：使用递归，每次将s1和s2分别分开成[0,i)与[i,len-1]两部分进行递归，通过将字符串排序判断字符串组成是否相同.|递归判断，排序判断字符组成.|
|P0088|合并两个有序数组|2019.11.12|描述：给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组.<br>思路：m+n为总长度，从后往前，从nums[n+m-1]开始对nums1重写，i=[n-1,0],j=[m-1,0],倒序合并，避免重复交换等操作.|倒序合并|
|P0089|格雷编码|2019.11.12|描述：给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头.<br>思路：从0开始，当flag = 1时，先添加1再加0，当flag=0时，先添加0再加1，进行递归.|递归实现|
|P0090|子集II|2019.11.16|描述：给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）.<br>思路：先对数组进行排序，然后分别找长度为[1,len]的子集，dfs深搜，需要去重.|需要去重|
|P0091|解码方法|2019.11.17|描述：给定一个只包含数字的非空字符串，请计算解码方法的总数.<br>思路：使用动态规划，pre为dp[i-1]，curr为dp[i]，分为4种情况.|注意复习|
|P0092|反转链表II|2019.11.14|描述：反转从位置 m 到 n 的链表。请使用一趟扫描完成反转.<br>思路：1.先找到翻转的开始位置；2.开始翻转并计数；3.前中后三部分进行拼接.|要仔细，pPrev，pCurr，pNext三个指针|
|P0093|复原IP地址|2019.11.14|描述：给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式.<br>思路：使用DFS递归方法，结束条件为index=size && times=4，即分为4段.|注意结束条件和剪枝|
|P0094|二叉树的中序遍历|2019.11.17|描述：给定一个二叉树，返回它的中序遍历.<br>思路：递归比较容易实现，迭代用栈实现，不断将左节点入栈，左节点为空是出栈并访问val，然后开始遍历右节点.|递归+迭代|
|P0095|不同的二叉搜索树II|2019.11.17|描述：给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树.<br>思路：不断以start-end为起点终点构建树，当start>end时，result中放入null，递归构建树.|注意复习|
|P0096|不同的二叉搜索树|2019.11.17|描述给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种.<br>思路：使用动态规划方法，以1-n为根计算.|注意复习|
|P0097|交错字符串|2019.11.19|描述：给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的.<br>思路：方法1.递归回溯，但会超时；方法2.动态规划，dp[len1+1][len2+1].|掌握方法1和2|
|P0098|验证二叉搜索树|2019.11.18|描述：给定一个二叉树，判断其是否是一个有效的二叉搜索树.<br>思路：使用中序遍历思想进行验证，中序遍历应该是一个严格递归序列，否则返回false；方法1.递归；方法2.迭代.|递归+迭代|
|P0099|恢复二叉搜索树|2019.11.20|描述：二叉搜索树中的两个节点被错误地交换，请在不改变其结构的情况下，恢复这棵树.<br>思路：找个两个数，首次满足 num > root->val,则 targetNum1 = num,最后一次满足 num > root->val，则 targetNum1 = root->val,然后再中序遍历进行交换.|两次中序遍历，第一次寻找，第二次交换|
|P0100|相同的树|2019.11.19|描述：给定两个二叉树，编写一个函数来检验它们是否相同。如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的.<br>思路：方法1.直接递归判断，采用先序遍历思想，不断比较节点值；方法2.使用迭代方法，采用层序遍历思想.|先序遍历+层序遍历|
|P0101|对称二叉树|2019.11.20|描述：给定一个二叉树，检查它是否是镜像对称的.<br>思路：对左右节点分别进行递归遍历，判断是否相等.|常考题，注意复习|
|P0102|二叉树的层次遍历|2019.11.20|描述：给定一个二叉树，返回其按层次遍历的节点值（即逐层地，从左到右访问所有节点).<br>思路：一次遍历每一层，使用 tempNodes 保存下一层的节点，然后将 tempNodes 赋值给 Nodes，迭代遍历.|也可以改为用队列|
|P0103|二叉树的锯齿形层次遍历|2019.11.20|描述：给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）.<br>思路：一次遍历每一层，使用 tempNodes 保存下一层的节点，然后将 tempNodes 赋值给 Nodes，迭代遍历.使用一个order标志位，进行翻转.|也可以改为用队列|
|P0104|二叉树的最大深度|2019.11.20|描述：给定一个二叉树，找出其最大深度.<br>思路：root为空返回0，否则递归，返回1+max(左子树深度，右子树深度).|深度递归DFS或者层序遍历BFS|
|P0105|从前序与中序遍历序列构造二叉树|2019.11.21|描述：根据一棵树的前序遍历与中序遍历构造二叉树.<br>思路：每次将preorder的首元素构造树节点，然后提取left_inorder,left_preorder和right_inorder,right_preorder，进行进一步构造.|掌握方法|
|P0106|从中序与后序遍历序列构造二叉树|2019.11.21|描述：根据一棵树的中序遍历与后序遍历构造二叉树.<br>思路：与105题相似，当前节点为 postorder的最后一个节点，然后构造left_inorder,left_postorder和right_inorder,right_postorder,递归构造左右子树.|注意复习掌握|
|P0107|二叉树的层次遍历II|2019.11.21|描述：给定一个二叉树，返回其节点值自底向上的层次遍历。(即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历).<br>思路：与普通层序遍历类似,在最后对result结果进行翻转即可。也可以先加入队列，然后再倒序访问队列.|熟练题目|
|P0108|将有序数组转换为二叉搜索树|2019.11.21|描述：将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树.<br>思路：每次找nums中间的节点作为当前节点值，然后递归建立搜索树.|注意复习|
|P0109|有序链表转换二叉搜索树|2019.11.22|描述：给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树.<br>思路：确定链表长度，然后每次取中间的节点，再递归构建左右子树.|常见题，要掌握|
|P0110|平衡二叉树|2019.11.22|描述：给定一个二叉树，判断它是否是高度平衡的二叉树.<br>思路：方法1.采用后序遍历思想，进行一次DFS即可得出结果；方法2.对每个结点调用的求深度的函数。|掌握方法1和方法2|
|P0111|二叉树的最小深度|2019.11.22|描述：给定一个二叉树，找出其最小深度.<br>思路：方法1.在计算树深度的基础上进行修改，如果叶子节点，则返回1，否则根据左右节点情况进一步递归；方法2.用层序遍历思想计算.|掌握方法1和方法2|
|P0112|路径总和|2019.11.22|描述：给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和.<br>思路：DFS深度优先搜索，当为叶子节点时，判断sum=root.val，等于为true，否则为false；非叶子节点，则递归判断左右子树.|也可以用BFS，即层序遍历思想.|
|P0113|路径总和II|2019.11.22|描述：给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径.<br>思路：采用DFS递归，当遇到叶子节点时，判断是否满足要求，非叶子节点则进行递归.|也可以采用BFS层序遍历实现|
|P0114|二叉树展开为链表|2019.11.22|描述：给定一个二叉树，原地将它展开为链表,右链表形式.<br>思路：将root作为根节点，然后对左右节点进行递归，将节点都链接到右子树，返回链表尾节点.|注意复习|
|P0115|不同子序列|2019.11.24|描述：给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数.<br>思路：使用动态规划方法，设计动态规划方程，完成计算.|掌握动态规划方程|
|P0116|填充每个节点的下一个右侧节点指针|2019.11.23|描述：填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL.<br>思路：每次将一整列连通，然后递归遍历左右子树.|记住思路|
|P0117|填充每个节点的下一个右侧节点指针II|2019.11.23|描述：填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL.<br>思路：将每层看做一个链表，再进行下一层时，利用上一层的链表进行遍历拼接.|掌握此方法|
|P0118|杨辉三角|2019.11.23|描述：给定一个非负整数 numRows，生成杨辉三角的前 numRows 行.<br>思路：一个元素等于它的上面两个元素的和，思路比较简单.|掌握即可|
|P0119|杨辉三角II|2019.11.23|描述：给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行.<br>思路：在计算普通杨辉三角的基础上，将上一行的结果进行保存，用于计算下一行的结果.|常规思路|
|P0120|三角形的最小路径和|2019.11.24|描述：给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上.<br>思路：方法1.DFS深度优先搜索，会超时；方法2.采用动态规划，自底向上，dpTable[j]的来源只有 dpTable[j] 或者 dpTable[j + 1].|掌握方法1和方法2|
|P0121|买卖股票的最佳时机|2019.11.1|描述：给定一个数组，它的第i个元素是一支给定股票第i天的价格。如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润.<br>思路：方法1.遍历数组，记录当前为止的最小值，然后第二次遍历计算最大利益，也可以优化为一次遍历；方法2.暴力求解.|方法2接近动态规划思想.|
|P0122|买卖股票的最佳时机II|2019.11.1|描述：给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格.设计一个算法来计算你所能获取的最大利润.<br>思路：计算差值，将所有差值为正表示能够获得收益，加差值为正的值累加.|其实也可以优化为一次遍历.|
|P0123|买卖股票的最佳时机III|2019.11.1|描述：给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你最多可以完成两笔交易.<br>思路：方法1：遍历一次，记录minLeft和maxRight，然后遍历更新result；方法2：先暴力法确定两个点，然后再遍历剩余数据；方法3:暴力法解决.|掌握方法1、2、3.|
|P0124|二叉树中的最大路径和|2019.11.24|描述：给定一个非空二叉树，返回其最大路径和,不一定经过根节点.<br>思路：left和right分别为左右子树的最大贡献值，result保存结果，然后分情况计算.|重点题目，要掌握.|
|P0125|验证回文串|2019.11.24|描述：给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写.<br>思路：先将字符串转为小写，然后用双指针法依次比较左右指针的字符是否相等.|也可以提取出字符和数字，然后翻转对比是否相等|
|P0126|单词接龙II|2019.11.26|描述：给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列.<br>思路：先计算出最短路径，在根据最短路径计算路径，即BFS+DFS，合理运用map和set.|BFS+DFS|
|P0127|单词接龙|2019.11.26|描述：给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度.<br>思路：使用BFS计算出最短转换序列.|BFS/双向BFS|
|P0128|最长连续序列|2019.12.2|描述：给定一个未排序的整数数组，找出最长连续序列的长度.<br>思路：将每个nums[i]-1不在序列中的数作为起点，然后进行遍历，能够保证比较时间复杂度为O(n)|暴力法/排序法时间复杂度较高|
|P0129|求根到叶子节点数字之和|2019.12.3|描述：给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字，计算从根到叶子节点生成的所有数字之和.<br>思路：使用DFS深度优先搜索，当遇到叶子节点时将数据进行累加，最后返回即可.|DFS深度优先搜索|
|P0130|被围绕的区域|2019.12.3|描述：给定一个二维的矩阵，包含 'X' 和 'O'（字母 O），找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充.<br>思路：对每个边缘的点进行BFS，并进行标记为'T'。之后将所有'O'(为'O'说明与边缘不相通)变为'X'，将'T'(所有与边界相通的'O'已全部别标记)变为'O'即可.|也不可以不用标记法，将'T'的坐标存在hashset中亦可.|
|P0131|分割回文串|2019.12.4|描述：给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串，返回 s 所有可能的分割方案.<br>思路：使用DFS深搜计算，注意递归结束条件.|DFS深搜.|
|P0132|分割回文串II|2019.12.4|描述：给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串，返回符合要求的最少分割次数.<br>思路：使用动态规划方法求解，f[i] = min(f[i] , f[j] + 1)|动态规划方法.|
|P0133|克隆图|2019.12.4|描述：给定无向连通图中一个节点的引用，返回该图的深拷贝(克隆).图中的每个节点都包含它的值 val(int)和其邻居的列表(list[Node]).<br>思路：1.根据原来节点的节点数，和节点值创建新的节点；2.根据原来节点的对应关系，连接新的对应节点|理解大概思路即可.|
|P0134|加油站|2019.12.26|描述：在一条环路上有 N 个加油站，其中第 i 个加油站有汽油gas[i]升，如果你可以绕环路行驶一周，则返回出发时加油站的编号.<br>思路：动态规划，1.找一个不可能为起点的点i；2.从start开始，填写dp；3.startvec中保存所有可能开始的起点；4.检查startvec中的每个点.|总的思路是找出所有可能开始的起点，然后检查，如果当前节点符合，且前一个也符合，则使用前一个的值，即dp[index] = dp[(index-1+num)%num].|
|P0135|分发糖果|2019.12.26|描述：老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分.<br>思路：两次扫描，从左往右，再从右往左，要求符合左右规则.|掌握两次扫描方法.|
|P0136|只出现一次的数字|2019.10.13|描述：给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素.<br>思路：两个相同的数异或等于0，因此将所有数进行异或，最后得到的数就是只出现一次的数.|常见面试题|
|P0137|只出现一次的数字II|2019.10.13|描述：给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素.<br>思路：采用二进制做法，计算每一位的累加和，如果是K的倍数，则改为为0；否则为1.|记住通用解法|
|P0138|复制带随机指针的链表|2019.12.26|描述：给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。要求返回这个链表的深拷贝。<br>思路：此题思路与P133克隆图一样，分为两步，1.建立新节点，建立新旧节点的map映射，并给val赋值；2.遍历节点，利用map建立新节点之间的映射.|掌握思路|
|P0139|单词拆分|2019.12.26|描述：给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词.<br>思路：方法1.DFS深搜，但是会超时；方法2.采用动态规划.|掌握动态规划思想|
|P0140|单词拆分II|2019.12.27|描述：给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子.<br>思路：方法1.使用DFS计算，超时；方法2.使用记忆化搜索方式，构造hashmap进行剪枝.|掌握两种方法.|
|P0141|环形链表|2019.12.26|描述：给定一个链表，判断链表中是否有环.<br>思路：方法1.使用map或者set，存储并检查是否重复访问；方法2.使用快慢指针，慢指针走一步，快指针走两步，重合则有环.|掌握两种方法.|
|P0142|环形链表II|2019.12.27|描述：给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null.<br>思路：分为3步，1.判断是否有环并计步；2.开始找入口，fast先走step步；3.相遇的时候为入口.|掌握步骤.|
|P0143|重排链表|2019.12.27|描述：给定一个单链表，改为前后交替的单链表.<br>思路：方法1.使用双端队列，然后依次出队并连接即可；方法2.(1)将链表分为左右两部分；(2)将后部分翻转；（3）将左右链表交替遍历并连接.|掌握方法1和方法2.|
|P0144|二叉树的前序遍历|2019.12.27|描述：给定一个二叉树，返回它的前序遍历.<br>思路：方法1.递归方法；方法2.非递归，使用栈实现，先插入右节点，再插入左节点.|掌握递归和非递归.|
|P0145|二叉树的后序遍历|2019.12.27|描述：给定一个二叉树，返回它的后序遍历.<br>思路：方法1.递归做法；方法2.BFS宽搜+逆序 = 后序.|掌握方法1和2.|
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
|P0174||2019.12.27|描述：.<br>思路：.||
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
|P0215|数组中的第K个最大元素|2019.12.27|描述：在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素.<br>思路：方法1.遍历K次，每次找最大值；方法2.使用优先队列构造最小堆，维护一个大小为K的堆.|掌握方法1和方法2.|
|P0217|存在重复元素|2019.10.28|描述：给定一个整数数组，判断是否存在重复元素，如果任何值在数组中出现至少两次,函数返回true,如果数组中每个元素都不相同，则返回false.<br>思路：方法1.检测任意两个元素是否重复O,复杂度(n^2)；方法2.排序再遍历是否相邻相等,复杂度(nlogn)；方法3.采用hashmap方法,复杂度(n).|掌握三种方法.|
|P0219|存在重复元素II|2019.10.28|描述：给定一个整数数组和一个整数k，判断数组中是否存在两个不同的索引i和j，使得nums[i]=nums[j]，并且i和j的差的绝对值最大为k.<br>思路：滑动窗口思想，要求(j-i)<=k,因此维护一个k+1大小的滑动窗口，判断nums[i]是否存在与当前滑动窗口内，存在则返回true.|窗口大小为k+1，当size=k+1时，先删除nums[i-k-1]，再判断是否重复.|
|P0220|存在重复元素III|2019.10.28|描述：给定一个整数数组，判断数组中是否有两个不同的索引i和j，使得 nums[i]和nums[j]的差的绝对值最大为t，并且i和j之间的差的绝对值最大为k.<br>思路：滑采用暴力法的滑动窗口会超时，因此采用二叉搜索树思想用set解决，num_double-t <= x，寻找第一个大于等于num_double-t的元素计算.|掌握暴力法和二叉树搜索树set方法.|
|P0230|二叉搜索树中第K小的元素|2019.12.27|描述：给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素.<br>思路：方法1.递归法进行中序遍历；方法2.非递归中序遍历.|掌握方法1和2.|
|P0234|回文链表|2019.12.25|描述请判断一个链表是否为回文链表，要求 O(n) 时间复杂度和 O(1) 空间复杂度.<br>思路：法1.将链表计算长度，并将后半部分存入vector或栈中，然后出栈比较；法2.使用快慢指针找到中点，然后翻转后半部分，最后遍历两部分比较.|重要题目，注意复习.|
|P0260|只出现一次的数字III|2019.10.13|描述：给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。找出只出现一次的那两个元素.<br>思路：将所有数字进行异或得到res，找到res中为1的位index，则num1在第index位为1，num2在第index位为0，分两类异或，得到结果.|系列I、II、III都要掌握.|
|P0980|不同路径III|2019.11.5|描述：返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目，每一个无障碍方格都要通过一次.<br>思路：使用递归回溯法，对走过的路径进行标记，回溯时取消标记，同时记录走过的空格数量，到终点且数量相等时符合要求.|熟练递归方法.|
