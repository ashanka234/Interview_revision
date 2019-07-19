    if(!head)       //empty list
        return;

    Node *curr = head;
    int count[3] = {0};

    //create frequency array
    while(curr)
    {
        count[curr->data]++;
        curr = curr->next;
    }

    int i=0;
    //i will traverse the count array

    curr = head;
    while(curr)
    {
        if(count[i] == 0)
        {
            i++;        //yeh wale sare laga diye, agla number bharo ab
        }

        curr->data = i;     //i is the number 0,1 or 2; array mei uska freq stored hai
        count[i]--;
        curr = curr->next;      //bas data overwrite kr rhe hain
    }