import heapq
import math

acts = {}
adj = {}
radj = {}
indeg = {}
outdeg = {}


def genKey(a, b):
    return str(a)+'-'+str(b)


def findLongestPath(deg, adj):
    pq = []
    t = {}
    for u, d in deg.items():
        if d == 0:
            t[u] = 0
            heapq.heappush(pq, (0, u))
    while pq:
        tu, u = heapq.heappop(pq)
        if tu < t[u]:
            continue
        for v in adj.get(u, []):
            k = genKey(u, v) if genKey(u, v) in acts else genKey(v, u)
            tv = tu+acts[k]['te']
            if t.get(v, 0) < tv:
                t[v] = tv
                heapq.heappush(pq, (tv, v))
    return t


def normpdf(x, mean, sd):
    var = float(sd)**2
    denom = (2*math.pi*var)**.5
    num = math.exp(-(float(x)-float(mean))**2/(2*var))
    return num/denom


n = int(input('Input no. of activities: '))

print('\nInput (i, j, To, Tm, Tp) for all activities:')
for i in range(n):
    line = input()
    u, v, to, tm, tp = list(map(lambda x: int(x), line.split()))

    k = genKey(u, v)
    acts[k] = {
        'name': chr(ord('A')+i),
        'te': (to+4*tm+tp)/6,
        'var': ((tp-to)/6)**2
    }

    if u in adj:
        adj[u].append(v)
    else:
        adj[u] = [v]
    indeg[u] = indeg.get(u, 0)
    outdeg[u] = outdeg.get(u, 0)+1

    if v in radj:
        radj[v].append(u)
    else:
        radj[v] = [u]
    indeg[v] = indeg.get(v, 0)+1
    outdeg[v] = outdeg.get(v, 0)

e = findLongestPath(indeg, adj)
l = findLongestPath(outdeg, radj)

pct = 0
for t in e.values():
    pct = max(pct, t)

cp = set()
print()
for act in acts.keys():
    u, v = list(map(lambda x: int(x), act.split('-')))

    es = e[u]
    ef = es+acts[act]['te']
    lf = pct-l[v]
    ls = lf-acts[act]['te']
    print('{}: Te={}, Var={}, ES={}, EF={}, LS={}, LF={}'.format(
        acts[act]['name'], acts[act]['te'], acts[act]['var'], es, ef, ls, lf))

    if es == ls:
        cp.add(u)
        cp.add(v)

print('\nProject Completion Time:', pct)

cp = sorted(cp, key=lambda x: e[x])
print('Critical Path:', ' - '.join(list(map(lambda x: str(x), cp))))

ca = []
pvar = 0
for i in range(1, len(cp)):
    k = genKey(cp[i-1], cp[i])
    ca.append(acts[k]['name'])
    pvar += acts[k]['var']

print('Critical Activities:', ', '.join(list(map(lambda x: str(x), ca))))
print('Variance: {}, Standard Deviation: {}'.format(pvar, math.sqrt(pvar)))

dd = int(input('\nInput due completion time: '))
z = (dd-pct)/math.sqrt(pvar)
print('\nProbability:', 0.5+(1 if z >= 0 else -1)*normpdf(z, 0, 1))
