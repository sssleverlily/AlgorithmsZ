class Solution {
public:
/**
top 访问栈顶元素
empty 检查底层的容器是否为空
size 返回容纳的元素数
push 向栈顶插入元素
pop 删除栈顶元素
swap 交换内容

看到括号以为就栈了，但是最后还是没有用栈
**/

    vector<string> result;
    vector<string> generateParenthesis(int n) {
        dfs("",n,n);
        return result;
    }

    void dfs(string str,int left,int right){
        if(left == 0 && right == 0){
            //都匹配完成
            result.push_back(str);
            return;
        }
        if (left > 0) {
            dfs(str + "(", left - 1, right);
        }      
        if (right > left) {
            dfs( str + ")",left, right - 1);
        }
        
    }
};