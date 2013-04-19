    ListNode *deleteDuplicates(ListNode *head) {
       
    
    ListNode *currentNode = head;
    if(currentNode == NULL)
        return head;
    
    ListNode* nextNode = currentNode->next;
    
    while(nextNode!= NULL)
    {
        if(currentNode->val == nextNode->val)
        {
            //currentNode->next = nextNode->next;
            ListNode* nodeToDelete = nextNode;
            nextNode = nextNode->next;
            currentNode->next = nextNode;
            delete nodeToDelete;
        }
        else
        {
            currentNode = nextNode;
            nextNode = nextNode->next;
        }
    } 
     return head;
    }
    
 //Second method
    
    ListNode *currentNode = head;
    
    while(currentNode != NULL)
    {
        ListNode* nextNode = currentNode->next;
        while(nextNode!= NULL)
        {
            if(currentNode->val == nextNode->val)
            {
                currentNode->next = nextNode->next;
                ListNode* nodeToDelete = nextNode;
                nextNode = nextNode->next;
                delete nodeToDelete;
            }
            else
            {
                currentNode = nextNode;
                break;
            }
        }
        currentNode = nextNode;
    }
      
     return head;
    }
