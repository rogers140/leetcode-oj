#include <stdio.h>
#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *currentl1, *currentl2;
       	currentl1 = l1;
       	currentl2 = l2;
        int carry = 0;
        int value = 0;
        int digit = 1; //please note that do not use digit*10 to increase digit.
        			   //int has its own range which could not be overflow
        unordered_map<int, int> hashmap;
        hashmap[1] = 0;
        while(1){
        	value = (currentl1->val +currentl2->val + carry)%10;
        	carry = (currentl1->val +currentl2->val + carry)/10;
        	hashmap[digit] = value;
        	if ((currentl1->next != NULL)&&(currentl2->next != NULL)){//both have more digits
        		currentl1 = currentl1->next;
        		currentl2 = currentl2->next;
        		digit = digit+1;
        		continue;
        	}
        	else{
        		break;
        	}
        }
        if ((currentl1->next == NULL)&&(currentl2->next == NULL)&&(carry == 1)){
        	digit = digit+1;
        	hashmap[digit] = 1;
        }
        else if ((currentl1->next == NULL)&&(currentl2->next != NULL)){
        	while(currentl2->next != NULL){
        		currentl2 = currentl2->next;
        		value = (currentl2->val + carry)%10;
        		carry = (currentl2->val + carry)/10;
        		digit = digit+1;
        		hashmap[digit] = value;
        	}
        	if(carry==1){
        		digit = digit+1;
        		hashmap[digit] = 1;
        	}
        }
        else if((currentl1->next != NULL)&&(currentl2->next == NULL)){
        	while(currentl1->next != NULL){
        		currentl1 = currentl1->next;
        		value = (currentl1->val + carry)%10;
        		carry = (currentl1->val + carry)/10;
        		digit = digit+1;
        		hashmap[digit] = value;
        	}
        	if(carry==1){
        		digit = digit+1;
        		hashmap[digit] = 1;
        	}
        }
        ListNode *result, *ptr;
        result =NULL;
        while (digit !=0){
        	ptr = new ListNode(hashmap[digit]);
        	ptr->next = result;
        	result = ptr;
        	digit = digit-1;
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
	ListNode a1(9);

	ListNode b1(1);
	ListNode b2(9);
	ListNode b3(9);
	ListNode b4(9);
	ListNode b5(9);
	ListNode b6(9);
	ListNode b7(9);
	ListNode b8(9);
	ListNode b9(9);
	ListNode b10(9);

	b1.next = &b2;
	b2.next = &b3;
	b3.next = &b4;
	b4.next = &b5;
	b5.next = &b6;
	b6.next = &b7;
	b7.next = &b8;
	b8.next = &b9;
	b9.next = &b10;
	

	ListNode *result = (new Solution())->addTwoNumbers(&a1, &b1);
	while(result!=NULL){
		cout<<result->val<<",";
		result = result->next;
	}
	cout<<endl;
	return 0;
}