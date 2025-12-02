/******************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/attribute-parser/problem?isFullScreen=true
 * 
 * Problem : The first line of the input consists of two space separated integers, N and Q. N specifies
 *           in the HRML source program and Q the number of queries. HRML is a made up language that 
 *           looks like this:
 *              <tag1 value = "HelloWorld">
 *              <tag2 name = "Name1">
 *              </tag2>
 *              </tag1>
 *           and the query looks like this:
 *              tag1.tag2~name
 *              tag1~name
 *              tag1~value
 *           The first query will return "Nam1" because it is the value in the attribute "name" of the 
 *           tag2, and given that it is nested in tag1, we call it through tag1.
 *           The second query will return "Not found" because tag1 has no "name" attribute.
 *           The third query will return "Helloworld" because it is the value in the attribute "value"
 *           of tag1 
 *******************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/**
 * @brief Represent a collection of useful elements retrieved from a tag line of the HRML file
 */
typedef struct bloc {
    string tag;        /**< Unique identifier of our element */
    string parent_tag; /**< Identifier of a parent element in case of nested element */
    string line;       /**< Content of the element */
}bloc_t;

/**
 * @brief Return the tag extracted from a line in the file
 * 
 * @param[in] user_line string containing the line to get the tag from
 * 
 * @return  The tag
 */
string GetTagFromLine(string user_line) {
    string tag = "";
    if (user_line[1] != '/')
        if (user_line.find(" ") != string::npos) {
            tag = user_line.substr(1, user_line.find(" ") -1);
        } else {
            tag = user_line.substr(1, user_line.length() - 2);
        }
    else
        tag = user_line.substr(2, user_line.length() -3);

    return tag;
}


/**
 * @brief Return a bloc from a list based on a tag
 * 
 * @param[in] bloc_list      List of blocs of entry
 * @param[in] bloc_list_len  Length of the blocs list
 * @param[in] tag            Tag of the bloc we're looking for
 * 
 * @return  The bloc if found in the list, an empty bloc otherwise
 */
bloc_t GetBlocFromTag(bloc_t * bloc_list, int bloc_list_len, string tag) {
    bloc_t bloc = {"", "", ""};
    for (int i = 0; i < bloc_list_len; i++) {
        if (bloc_list[i].tag == tag) {
            bloc = bloc_list[i];
            break;
        }
    }

    return bloc;
}

/**
 * @brief Check if the parent tag in a bloc is "None"
 * 
 *  When a bloc is at the root of the file, meaning it is not nested whithin
 *  another bloc, the parent tag is set at "None", so this function allows
 *  us to check if a bloc is at the root of the file (not nested ....)
 * 
 * @param[in] tag            Tag of the bloc to check
 * @param[in] bloc_list      List of blocs where we need to look
 * @param[in] bloc_list_len  Length of the blocs list
 * 
 * @return  true if the parent tag is "None", false otherwise
 */
bool ParentTagIsNone(string tag, bloc_t *bloc_list, int bloc_list_len) {
    bloc_t bloc = GetBlocFromTag(bloc_list, bloc_list_len, tag);
    if (bloc.parent_tag != "None")
        return false;
    
    return true;
}

/**
 * @brief Return an attribut's value given its name and the line containing it
 * 
 * @param[in] tag_line      String containing the tag and a attributs with associated values
 * @param[in] attribut_name String containing the tag and a list of attributs
 * 
 * @return The attribut's value
 */
string GetAttributValue(string tag_line, string attribut_name) {
    string reduced_tag_line = tag_line;
    string attribut_value;
    int string_postion; // Help to parse and break the tag line, Note that it's the postion of the string's first character!!!
    
    do {
        string_postion = reduced_tag_line.find(" ");
        if (string_postion != string::npos) { // meaning that the string has been found in the line
            reduced_tag_line = reduced_tag_line.substr(string_postion + 1);
            string_postion = reduced_tag_line.find(" ");
            if (string_postion != string::npos) {
                string temp_attribut_name = reduced_tag_line.substr(0, string_postion);
                reduced_tag_line = reduced_tag_line.substr(string_postion + 1);
                reduced_tag_line = reduced_tag_line.substr(reduced_tag_line.find("= \"") + 3); // Find only give the position of the first character!!!!!
                attribut_value = reduced_tag_line.substr(0, reduced_tag_line.find("\""));
                if (temp_attribut_name == attribut_name) {
                    break;
                }
            }
        } else {
            attribut_value = "Not Found!";
        }
    } while(string_postion != string::npos);

    return attribut_value;
}

/**
 * @brief Check if tag parenting is correct
 * 
 * The user's query may contains multiples tags separated by a dots, the order in which these
 * are given in the query must match the nesting tree in the HRML file, meaning each tag in the
 * query must always be preceded by its parent tag and must always be followed by one of its
 * immediate child tag, and the first tag must always be a root tag
 * 
 * @param [in] query_tags    List of query tags separated by dots
 * @param [in] bloc_list     List of blocs
 * @param [in] bloc_list_len Length of the list of blocs
 * 
 * @return true if the list of tags is properly ordered, false otherwise
 */
bool TagsParentingIsCorrect(string query_tags, bloc_t *bloc_list, int bloc_list_len) {
    string reduced_query_tags = query_tags;
    string first_tag = query_tags.substr(0, query_tags.find("."));
    string second_tag;
    bool proper_order = true;
    if (ParentTagIsNone(first_tag, bloc_list, bloc_list_len)) { // The root tag is not a nested one
        while(reduced_query_tags.find(".") != string::npos) { // The reduced query tags has at least one ".", so there are at least 2 tags
            reduced_query_tags = reduced_query_tags.substr(reduced_query_tags.find(".") + 1);
            if (reduced_query_tags.find(".") != string::npos) {
                second_tag = reduced_query_tags.substr(0, reduced_query_tags.find("."));
            } else {
                second_tag = reduced_query_tags;
            }
            bloc_t b = GetBlocFromTag(bloc_list, bloc_list_len, second_tag);
            if (b.parent_tag != first_tag) {
                proper_order = false;
                break;
            }
            first_tag = second_tag;
        }
    } else {
        proper_order = false;
    }

    return proper_order;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;                // Number of lines in our HRML file
    int Q;                // Number of queries
    int bloc_idx = 0;     // Element index from the list
    string attribut_name;          // The attribut from the query=
    string direct_tag;    // The tag directly associated to the attribut
    string tags_string;   // The part of the query that only contains tags
    string user_line;     // Line enter by the user
    string last_open_tag; // The last open tag whitout a corresponding closing tag

    // Get the number of line in the HRML file and the number of queries
    cin>>N>>Q;
    cin.ignore();
    bloc_t bloc_list[N/2]; // List of language elements

    // Parse the HRML file line by line
    for(int i = 0; i < N; i++) {
        getline(cin, user_line);
        if (user_line[1] != '/') { // Starting of a bloc
            if (bloc_idx == 0) // First element of the file
                bloc_list[bloc_idx].parent_tag = "None";
            else
                bloc_list[bloc_idx].parent_tag = last_open_tag;
            
            bloc_list[bloc_idx].tag = GetTagFromLine(user_line);
            bloc_list[bloc_idx].line = user_line;
            last_open_tag = bloc_list[bloc_idx].tag;
            bloc_idx++;
        } else { // Closing bloc
            bloc_t b  = GetBlocFromTag(bloc_list, N/2, GetTagFromLine(user_line));
            last_open_tag = b.parent_tag;
        }

    }

    // Get and respond to queries
    for (int i = 0; i < Q; i++) {
        getline(cin, user_line);
        attribut_name = user_line.substr(user_line.find("~") + 1);
        tags_string = user_line.substr(0, user_line.find("~"));
        if (tags_string.find(".") == string::npos) {
            bloc_t b = GetBlocFromTag(bloc_list, N/2, tags_string);
            if (b.parent_tag != "None") {
                cout<<"Not Found!"<<endl;
            } 
            else {
                cout<<GetAttributValue(b.line, attribut_name)<<endl;
            }
        } else {
            direct_tag = tags_string.substr(tags_string.rfind(".") + 1);
            if (TagsParentingIsCorrect(tags_string, bloc_list, N/2)) {
                bloc_t b = GetBlocFromTag(bloc_list, N/2, direct_tag);
                cout<<GetAttributValue(b.line, attribut_name)<<endl;
            } else {
                cout<<"Not Found!"<<endl;
            }
        }
    }
    return 0;
}

/* input
20 19
<tag1 v1 = "123" v2 = "43.4" v3 = "hello">
</tag1>
<tag2 v4 = "v2" name = "Tag2">
<tag3 v1 = "Hello" v2 = "World!">
</tag3>
<tag4 v1 = "Hello" v2 = "Universe!">
</tag4>
</tag2>
<tag5>
<tag7 new_val = "New">
</tag7>
</tag5>
<tag6>
<tag8 intval = "34" floatval = "9.845">
<ntag nv = "4$">
<nvtag nv = "6$">
</nvtag>
</ntag>
</tag8>
</tag6>

<tag1 v1 = "123" v2 = "43.4" v3 = "hello">
</tag1>
<tag2 v4 = "v2" name = "Tag2">
    <tag3 v1 = "Hello" v2 = "World!">
    </tag3>
    <tag4 v1 = "Hello" v2 = "Universe!">
    </tag4>
</tag2>
<tag5>
    <tag7 new_val = "New">
    </tag7>
</tag5>
<tag6>
    <tag8 intval = "34" floatval = "9.845">
        <ntag nv = "4$">
            <nvtag nv = "6$">
            </nvtag>
        </ntag>
    </tag8>
</tag6>

tag1~v1 123
tag1~v2 43.4
tag1~v3 hello
tag4~v2 NF
tag2.tag4~v1 Hello
tag2.tag4~v2 Universe!
tag2.tag3~v2 World!
tag5.tag7~new_val New
tag5~new_val NF
tag7~new_val NF
tag6.tag8~intval 34
tag6.tag8~floatval 9.845
tag6.tag8~val NF
tag8~intval NF
tag6.tag8.ntag~nv 4$
tag6.tag8.ntag.nvtag~nv 6$
tag6.tag8.nvtag~nv nf
randomtag~nv nf
tag283.tag21.den~jef nf
*/

/* Designing
Get line
    attr = extract_attr_from_line(line)
    link_tag = extract_tag_from_line(rest_of_line)
    bloc =  GetBlocFromTag(bloc_list, list_len, link_tag)
    if attr+" = " in bloc.line 
    if rest_of_line contains "." // multiple tags
        while (something)
            if last_tag.parent != before

Get line
    if tag_begin
        if index_bloc = 0
            bloc_list[index_bloc].parent_tag = "None"
        else
            bloc_list[index_bloc].parent_tag = last_open_tag
            
        bloc_list[index_bloc].tag = extract tag from_line
        bloc_list[index_bloc].line = line
        last_open_tag = bloc_list[index_bloc].tag
        index_bloc++

    else //tag_end
        current_bloc = GetBlocFromTag(bloc_list, list_len, extract_tag_from(line))
        last_open_tag = current_bloc.parent_tag
*/
