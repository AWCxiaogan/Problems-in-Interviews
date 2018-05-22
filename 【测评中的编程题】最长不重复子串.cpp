size_t longest_unique_substr_len(const string& s) {
	vector<size_t> recorde(26, -1);
	size_t left = 0, maxlen = 0;
	for (size_t i = 0;i != s.size();++i) {
		size_t letter = s[i] - 'a';
		if (recorde[letter] != -1 && recorde[letter]>=left) {	//字母letter已出现，且在当前子串范围内
			maxlen = max(maxlen, i - left);
			left = recorde[letter] + 1;		//更新子串起始位置
		}
		recorde[letter] = i;				//记录字母对应给定字符串的位置
	}
	return max(maxlen, s.size() - left);
}