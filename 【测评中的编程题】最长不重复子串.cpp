size_t longest_unique_substr_len(const string& s) {
	vector<size_t> recorde(26, -1);
	size_t left = 0, maxlen = 0;
	for (size_t i = 0;i != s.size();++i) {
		size_t letter = s[i] - 'a';
		if (recorde[letter] != -1 && recorde[letter]>=left) {	//��ĸletter�ѳ��֣����ڵ�ǰ�Ӵ���Χ��
			maxlen = max(maxlen, i - left);
			left = recorde[letter] + 1;		//�����Ӵ���ʼλ��
		}
		recorde[letter] = i;				//��¼��ĸ��Ӧ�����ַ�����λ��
	}
	return max(maxlen, s.size() - left);
}