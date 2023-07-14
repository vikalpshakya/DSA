//   Time complexity = O(n*log(n)) , Space complexity O(n)  

Node* mergeTwoLists(Node* list1, Node* list2) {
		if (list1 == NULL) return list2;
		
		if (list2 == NULL) return list1;

		if (list1->data < list2->data) {
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		} 
		else {
			list2->next = mergeTwoLists(list1, list2->next);
			return list2;
	}
												}

Node* findMidPoint(Node* head) {
	if (head == NULL || head->next == NULL) {
			return head;
	}
	Node* slow = head;
	Node* fast = head->next;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* mergeSort(Node* head) {
	if (head == NULL || head->next == NULL) {
			return head;
	}
					
	Node* mid = findMidPoint(head);
	Node* midNext = mid->next;
	mid->next = NULL;
	Node* left = mergeSort(head);
	Node* right = mergeSort(midNext);
	return mergeTwoLists(left, right);
}
