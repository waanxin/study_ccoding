/*
1528. 重新排列字符串
给你一个字符串 s 和一个 长度相同 的整数数组 indices 。
请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。
返回重新排列后的字符串。 
*/

char * restoreString(char * s, int* indices, int indicesSize){ //条件给定字符串S 数组indices 和数组大小
char* new_str=(char*)malloc(indicesSize+1);//为新的字符串申请一个内存，注意最后一位需要存放 \0 代表字符串存放结束
    char *p=s;//保存S的地址
    int i;
    for(i=0;i<indicesSize;i++)//循环数组大小次数
    {
        char temp=s[i];//每次得到此时对应的s的字符
        new_str[indices[i]]=temp;//查看此时这个字符串中的字符对应的是数组中的什么位置，然后在新建的字符串中，放进合适的位置
    }
   *(new_str+indicesSize)='\0';//循环结束后，最后一位需要放 \0 代表这个字符串结束
    return new_str;//返回新的字符串的首地址
}