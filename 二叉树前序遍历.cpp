template <typename T>
void travPrev_I2(BinNodePosi(T) x, VST& visit) {
	Stack<BinNodePosi(T)> S;
	while (true) {

		while (x) {
			visit(x->data);
			S.push(x->rChild);
			x = x->lChild;
		}


		if (S.empty()) break;
		x = S.pop();
	}
}
