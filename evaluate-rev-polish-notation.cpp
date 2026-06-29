
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
       int n=tokens.size();
       
        for(int i=0;i<n;++i)
        {
            
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
               int first= stoi(st.top());
               st.pop();
               int sec=stoi(st.top());
               st.pop();
               if(tokens[i]=="+")
               st.push(to_string(sec+first));
               if(tokens[i]=="-")
               st.push(to_string(sec-first));
               if(tokens[i]=="*")
               st.push(to_string(sec*first));
               if(tokens[i]=="/")
               st.push(to_string(sec/first));
               
            }
            else
            st.push(tokens[i]);
        }
        return stoi(st.top());
    }
