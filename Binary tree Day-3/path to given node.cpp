void Paths(Node* root, int target) {
    vector<int> path;
    stack<Node*> nodeStack;
    Node* curr = root;
    Node* prev = NULL; 
    while (curr || !nodeStack.empty()){
        while (curr){
            nodeStack.push(curr);
            path.push_back(curr->data);
            curr = curr->left;
        }        
        curr = nodeStack.top();      
        if (curr->right && curr->right != prev){
            curr = curr->right;
        }else{
            if (curr->data == target){
                for(int i = 0; i<path.size()-1; i++)
                    cout<<path[i]<<"->";
                cout<<path[path.size()-1]<<endl;
                return;
            }
            nodeStack.pop();
            path.pop_back();
            prev = curr;
            curr = NULL;
        }
    }
    cout<<"No Path"<<endl;
}
