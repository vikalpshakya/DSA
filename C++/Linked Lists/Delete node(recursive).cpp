Node *deleteNodeRec(Node *head, int pos) {
      if(head==NULL) return NULL;
          if (pos == 0) {
            head = head->next;
            return head;
                        }
      Node *temp = deleteNodeRec(head->next, pos - 1);

      head->next = temp;
      return head;
}
