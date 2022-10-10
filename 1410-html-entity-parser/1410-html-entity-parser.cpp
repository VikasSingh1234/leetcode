class Solution {
public:
    string entityParser(string text) {
        unordered_map<string,string> html;
        html["&quot;"] = '\"';
        html["&apos;"] = "\'";
        html["&amp;"] = '&';
        html["&gt;"] = '>';
        html["&lt;"] = '<';
        html["&frasl;"] = '/';
        
        string s;
        int start=0,end=0;
        for(int i=0;i<text.length();i++,end++){
            if(text[i]=='&'){
                start = end;
            }
            if(text[i]==';'){
                s = text.substr(start,end-start+1);
                
                if(html.find(s)!=html.end()){
                    text.replace(start,end-start+1,html[s]);
                    i =i-(end-start)+(html[s].length());
                    end = i;
                    start = i;
                }
            }
        }
        return text;
    }
};