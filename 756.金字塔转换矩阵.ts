/*
class Solution(object):
    def pyramidTransition(self, bottom, allowed):
        T = [[0] * (1 << 7) for _ in xrange(1 << 7)]
        for triple in allowed:
            u, v, w = (1 << (ord(x) - ord('A')) for x in triple)
            for b1 in xrange(1 << 7):
                if u & b1:
                    for b2 in xrange(1 << 7):
                        if v & b2:
                            T[b1][b2] |= w

        state = [1 << (ord(x) - ord('A')) for x in bottom]
        while len(state) > 1:
            for i in xrange(len(state) - 1):
                state[i] = T[state[i]][state[i+1]]
            state.pop()
        return bool(state[0])
*/