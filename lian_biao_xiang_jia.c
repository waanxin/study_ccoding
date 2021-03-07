/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));//创建一个链表，并申请内存
    l3->next = NULL;//设置这个链表指向结尾NULL
    struct ListNode* ptr = l3;//使用临时指针代替这个链表
    struct ListNode* p1 = l1, *p2 = l2;//使用临时指针代替这个链表
    int nLoop = 0;//设置循环次数，这个如果是0次，代表两个需要相加的链表只包含一个节点
    int tem_val = 0;//代表相加的和是否大于10，大于或者等于下一次就变为1，下一次加上的时候等于十位进1
    int temp = 0;//l1和l2以及tem_val相加之后的值，如果大于10需要减去10，将最后运算的结果存进l3中
    while (1){//一直循环，除非l1和l2都循环完毕，才跳出
        if(p1 == NULL && p2 == NULL){//如果两个链表都到结尾后，需要跳出循环，同时需要判断上次相加的数目有没有大于10，如果大于10需要进位
            if(tem_val != 0)//判断上次的相加的数有没有大于10，有的话l3还需要再进位增加一位1
            {
                struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
                node->val = 1;//设置当前节点为1
                node->next = NULL;//当前节点变为末尾节点，指向null
                ptr->next = node;//将申请创建的节点添加进当前链表中
            }
            break;
        }else if(p1 != NULL && p2 == NULL){//l2链表循环完毕，
            temp = p1->val + tem_val;
        }
        else if(p1 == NULL && p2 != NULL){//l1链表循环完毕
            temp = p2->val + tem_val;
        }
        else{//两个链表都没有循环完毕，都需要执行相加操作
            temp = p1->val + p2->val + tem_val;
        }
        //开始处理需要存入l3的temp值，以及下一次相加的tem_val
        if (temp>=10){//相加大于10，需要进位
            tem_val = 1;
            temp = temp - 10;
        }else{//结果未大于10，直接存入即可。保证tem_val进位操作符为0
            tem_val = 0;
        }
        //开始存数
        if(nLoop == 0)//代表第一次循环
        {
            ptr->val = temp;//存入当前的数
            ptr->next = NULL;//节点指向null
        }else//代表不是第一次循环，即这个节点不是第一个节点，需要增加节点，并将新节点添加进当前节点之后
        {
            struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));//为新节点申请内存
            node->val = temp;//存入当前值
            node->next = NULL;//节点指向null
            ptr->next = node;//插入进当前的链表中的末尾
            ptr = ptr->next;//当前指针移动至末尾
        }
        nLoop++;//循环次数加1，其实这个循环次数可以不计算，只要保证在第一次节点存数的时候不需要申请内存即可
        if(p2!=NULL)//如果l2还没有结束，指针前进，
        {
            p2 = p2->next;
        }
        if(p1!=NULL)//l1指针前进
        {
            p1 = p1->next;
        }
    }
    return l3;//返回当前创建的指针的头部
}