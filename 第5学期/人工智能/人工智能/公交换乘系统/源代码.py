line1 = u'''苹果园 古城路 八角游乐园 八宝山 玉泉路 五棵松 万寿路 公主坟 军事博物馆 木樨地
南礼士路 复兴门 西单 天安门西 天安门东 王府井 东单 建国门 永安里 国贸 大望路 四惠 四惠东'''
line2 = u'''西直门 车公庄 阜成门 复兴门 长椿街 宣武门 和平门 前门 崇文门 北京站 建国门
朝阳门 东四十条 东直门 雍和宫 安定门 鼓楼大街 积水潭'''
line5 = u'''宋家庄 刘家窑 蒲黄榆 天坛东门 磁器口 崇文门 东单 灯市口 东四 张自忠路
北新桥 雍和宫 和平里北街 和平西桥 惠新西街南口 惠新西街北口 大屯桥东 北苑路北 立水桥南 立水桥 天通苑南 天通苑 天通苑北'''
line4 = u'''天宫院 生物医药基地 义和庄 黄村火车站 黄村西大街 清源路 枣园 高米店南
高米店北 西红门 新宫 公益西桥 角门西 马家堡 北京南站 陶然亭 菜市口 宣武门 西单 灵境胡同 西四
平安里 新街口 西直门 动物园 国家图书馆 魏公村 人民大学 海淀黄庄 中关村 北京大学东门 圆明园 西苑 北宫门 安河桥北'''
line6 = u'''海淀五路居 慈寿寺 白石桥南 车公庄西 车公庄 平安里 北海北 南锣鼓巷 东四 朝阳门 东大桥
呼家楼 金台路 十里堡 青年路 褡裢坡 黄渠 常营 草房 物资学院路 通州北关 通运门 北运河西 北运河东 郝家府 东夏园 潞城'''
line7 = u'''北京西站 湾子 达官营 广安门内 菜市口 虎坊桥 珠市口 桥湾 磁器口 广渠门内 广渠门外 双井 九龙山 大郊亭 百子湾 化工 南楼梓庄 欢乐谷景区 垡头 焦化厂 黄厂 郎辛庄 黑庄户 双合 万盛西 万盛东 
群芳 高楼金 花庄 环球度假区 '''
line8 = u'''朱辛庄 育知路 平西府 回龙观东大街 霍营 育新 西小口 永泰庄 林萃桥 森林公园南门
奥林匹克公园 奥体中心 北土城 安华桥 鼓楼大街 什刹海 南锣鼓巷'''
line9 = u'''国家图书馆 白石桥南 白堆子 军事博物馆 北京西站 六里桥东 六里桥 七里庄
丰台东大街 丰台南路 科怡路 丰台科技园 郭公庄'''
line10 = u'''劲松 双井 国贸 金台夕照 呼家楼 团结湖 农业展览馆 亮马桥 三元桥 太阳宫 芍药居
惠新西街南口 安贞门 北土城 健德门 牡丹园 西土城 知春路 知春里 海淀黄庄 苏州街 巴沟 火器营
长春桥 车道沟 慈寿寺 西钓鱼台 公主坟 莲花桥 六里桥 西局 泥洼 丰台站 首经贸 纪家庙 草桥
角门西 角门东 大红门 石榴庄 宋家庄 成寿寺 分钟寺 十里河 潘家园'''
line13 = u'''西直门 大钟寺 知春路 五道口 上地 西二旗 龙泽 回龙观 霍营 立水桥 北苑 望京西
                        芍药居 光熙门 柳芳 东直门'''
line14 = u'''张郭庄 园博园 大瓦窑 郭庄子 打井 七里庄 西局'''
line15 = u'''俸伯 顺义 石门 南法信 后沙峪 花梨坎 国展 孙河 马泉营 崔各庄望京 望京西'''
YiZhuangLine = u'''宋家庄 肖村 小红门 旧宫 亦庄桥 亦庄文化园 万源街 荣京东街 荣昌东街
                       同济南路 经海路 次渠南 次渠'''
FangShanLine = u'''郭公庄 大葆台 稻田 长阳 篱笆房 广阳城 良乡大学城北 良乡大学城 良乡大学城西 良乡南关 苏庄'''
ChangPingLine = u'西二旗 生命科学园 朱辛庄 巩华城 沙河 沙河高教园 南邵'
BaTongLine = u'''四惠 四惠东 高碑店 中国传媒大学 双桥 管庄 八里桥 通州北苑 果园 九棵树 梨园 临河里 土桥 '''
busline1 = u'''八王坟 大北窑 永安里 日坛路 北京站口 东单 中山公园 西单 复兴门 礼士路 工会大楼 木樨地 军事博物馆 公主坟 六里桥北里 马官营'''
busline2 = u'''海户屯 木樨园 永定门 天桥 前门 东华门 妇产医院 沙滩 宽街'''
busline3 = u'''广渠门 斜街 铁辘轳把 小市口 羊市口 花市 崇文门 正义路 南口 南池子 东华门 骑河楼 北池子 景山东街 地安门'''
busline4 = u'''六里桥 什坊院 公主坟 军事博物馆 木樨地 礼士路 西单 天安门 东单 北京站口 日坛路 永安里 大北窑 八王坟'''
busline5 = u'''德胜门环岛 德胜门 果子市 甘石桥 铸钟厂 鼓楼 地安门 景山后街 西板桥 北海 西华门 南长街 前门'''
busline6 = u'''六里桥 莲花池 湾子 甘石桥 达官营 广安门 白广路北口 牛街 菜市口 果子巷 虎坊桥 永安路 友谊医院 天桥 金鱼池 天坛 北门 红桥 法华寺 体育馆西路 北京体育馆 北京游乐园'''
busline7 = u'''动物园 展览馆 西直门外 西直门内 马相胡同 新开胡同 宝产胡同 祖家街 报子胡同 白塔寺 丰盛胡同 辟才胡同 太平桥 民族文化宫 新文化街 宣武门内 六部口 和平门'''
busline8 = u'''东单 崇文门 磁器口 榄杆市 培新街 幸福大街 北京体育馆 光明楼'''
busline9 = u'''金台路 水碓子 小庄 呼家楼 光华路 大北窑 永安里 日坛路 北京站 崇文门 台基厂 正义路 前门'''
busline10 = u'''复兴门 民族文化宫 西单 六部口 中山公园 天安门 王府井 东单 北京站口 北京站 '''
busline11 = u'''大北窑 郎家园 八王坟 火车站 九龙山 化工路西口 化工厂 大郊亭北站 东石门 唐家村 四根旗杆 方家村 半壁店 '''
busline12 = u'''五间楼 横七条 铁匠营 方庄南口 方庄 八里河 左安门 游泳池 北京游乐园 光明楼 夕照寺 广渠门'''
busline13 = u'''三里河 三里河东口 社会路 儿童医院 月坛 阜外大街 阜成门 白塔寺 西四 报子胡同 平安里 厂桥 东官房 北海后门 地安门 罗鼓巷 宽街 十条 船板胡同 北新桥 国子监 雍和宫 北小街豁口 和平里南口 
和平里 和平里商锄和平街北口 '''
busline14 = u'''角门南站 角门 西马厂北口 马家堡东口 洋桥 四通路 游泳池 太平街 虎坊桥 琉璃厂 和平门 六部口 力学胡同 灵境胡同 府右街 西安门 后库'''


def build_Line(**lines):
    """
    Input is build_Line(linename='station1 station2...'...)
    Ouput is a dictionary like {station:{neighbor1:line number,neighbor2:line number,...},station2:{...},...}
    """
    for key in lines.keys():
        value = lines[key]
        lines[key] = value.split()
    stations = set()
    for key in lines.keys():
        stations.update(set(lines[key]))
    system = {}
    for station in stations:
        next_station = {}
        for key in lines:
            if station in lines[key]:
                line = lines[key]
                idx = line.index(station)
                if idx == 0:
                    next_station[line[1]] = key
                elif idx == len(line) - 1:
                    next_station[line[idx - 1]] = key
                else:
                    next_station[line[idx - 1]] = key
                    next_station[line[idx + 1]] = key
        system[station] = next_station
    return system


def update_subway(BeiJingSubway):
    """
    因为 line2 and line10 是环形线路.
    故我们需要更新线路
    """
    BeiJingSubway[u'西直门'][u'积水潭'] = 'line2'
    BeiJingSubway[u'积水潭'][u'西直门'] = 'line2'
    BeiJingSubway[u'劲松'][u'潘家园'] = 'line10'
    BeiJingSubway[u'潘家园'][u'劲松'] = 'line10'
    return BeiJingSubway


bj_subway = build_Line(line1=u'''苹果园 古城路 八角游乐园 八宝山 玉泉路 五棵松 万寿路 公主坟 军事博物馆 木樨地
南礼士路 复兴门 西单 天安门西 天安门东 王府井 东单 建国门 永安里 国贸 大望路 四惠 四惠东''',
                         line2=u'''西直门 车公庄 阜成门 复兴门 长椿街 宣武门 和平门 前门 崇文门 北京站 建国门
朝阳门 东四十条 东直门 雍和宫 安定门 鼓楼大街 积水潭''',
                         line5=u'''宋家庄 刘家窑 蒲黄榆 天坛东门 磁器口 崇文门 东单 灯市口 东四 张自忠路
北新桥 雍和宫 和平里北街 和平西桥 惠新西街南口 惠新西街北口 大屯桥东 北苑路北 立水桥南 立水桥 天通苑南 天通苑 天通苑北''',
                         line4=u'''天宫院 生物医药基地 义和庄 黄村火车站 黄村西大街 清源路 枣园 高米店南
高米店北 西红门 新宫 公益西桥 角门西 马家堡 北京南站 陶然亭 菜市口 宣武门 西单 灵境胡同 西四
平安里 新街口 西直门 动物园 国家图书馆 魏公村 人民大学 海淀黄庄 中关村 北京大学东门 圆明园 西苑 北宫门 安河桥北''',
                         line6=u'''海淀五路居 慈寿寺 白石桥南 车公庄西 车公庄 平安里 北海北 南锣鼓巷 东四 朝阳门 东大桥
呼家楼 金台路 十里堡 青年路 褡裢坡 黄渠 常营 草房 物资学院路 通州北关 通运门 北运河西 北运河东 郝家府 东夏园 潞城''',
                         line7=u'''北京西站 湾子 达官营 广安门内 菜市口 虎坊桥 珠市口 桥湾 磁器口 广渠门内 广渠门外 双井 九龙山 大郊亭 百子湾 化工 南楼梓庄 欢乐谷景区 垡头 焦化厂 黄厂 郎辛庄 黑庄户 双合 万盛西 万盛东 
群芳 高楼金 花庄 环球度假区 ''',
                         line8=u'''朱辛庄 育知路 平西府 回龙观东大街 霍营 育新 西小口 永泰庄 林萃桥 森林公园南门
奥林匹克公园 奥体中心 北土城 安华桥 鼓楼大街 什刹海 南锣鼓巷''',
                         line9=u'''国家图书馆 白石桥南 白堆子 军事博物馆 北京西站 六里桥东 六里桥 七里庄
丰台东大街 丰台南路 科怡路 丰台科技园 郭公庄''',
                         line10=u'''劲松 双井 国贸 金台夕照 呼家楼 团结湖 农业展览馆 亮马桥 三元桥 太阳宫 芍药居
惠新西街南口 安贞门 北土城 健德门 牡丹园 西土城 知春路 知春里 海淀黄庄 苏州街 巴沟 火器营
长春桥 车道沟 慈寿寺 西钓鱼台 公主坟 莲花桥 六里桥 西局 泥洼 丰台站 首经贸 纪家庙 草桥
角门西 角门东 大红门 石榴庄 宋家庄 成寿寺 分钟寺 十里河 潘家园''',
                         line13=u'''西直门 大钟寺 知春路 五道口 上地 西二旗 龙泽 回龙观 霍营 立水桥 北苑 望京西
                        芍药居 光熙门 柳芳 东直门''',
                         line14=u'''张郭庄 园博园 大瓦窑 郭庄子 打井 七里庄 西局''',
                         line15=u'''俸伯 顺义 石门 南法信 后沙峪 花梨坎 国展 孙河 马泉营 崔各庄望京 望京西''',
                         YiZhuangLine=u'''宋家庄 肖村 小红门 旧宫 亦庄桥 亦庄文化园 万源街 荣京东街 荣昌东街
                       同济南路 经海路 次渠南 次渠''',
                         FangShanLine=u'''郭公庄 大葆台 稻田 长阳 篱笆房 广阳城 良乡大学城北 良乡大学城 良乡大学城西 良乡南关 苏庄''',
                         ChangPingLine=u'西二旗 生命科学园 朱辛庄 巩华城 沙河 沙河高教园 南邵',
                         BaTongLine=u'''四惠 四惠东 高碑店 中国传媒大学 双桥 管庄 八里桥 通州北苑 果园 九棵树 梨园 临河里 土桥 111''',
                         busline1=u'''八王坟 大北窑 永安里 日坛路 北京站口 东单 中山公园 西单 复兴门 礼士路 工会大楼 木樨地 军事博物馆 公主坟 六里桥北里 马官营''',
                         busline2=u'''海户屯 木樨园 永定门 天桥 前门 东华门 妇产医院 沙滩 宽街''',
                         busline3=u'''广渠门 斜街 铁辘轳把 小市口 羊市口 花市 崇文门 正义路 南口 南池子 东华门 骑河楼 北池子 景山东街 地安门''',
                         busline4=u'''六里桥 什坊院 公主坟 军事博物馆 木樨地 礼士路 西单 天安门 东单 北京站口 日坛路 永安里 大北窑 八王坟''',
                         busline5=u'''德胜门环岛 德胜门 果子市 甘石桥 铸钟厂 鼓楼 地安门 景山后街 西板桥 北海 西华门 南长街 前门''',
                         busline6=u'''六里桥 莲花池 湾子 甘石桥 达官营 广安门 白广路北口 牛街 菜市口 果子巷 虎坊桥 永安路 友谊医院 天桥 金鱼池 天坛 北门 红桥 法华寺 体育馆西路 
                         北京体育馆 北京游乐园''',
                         busline7=u'''动物园 展览馆 西直门外 西直门内 马相胡同 新开胡同 宝产胡同 祖家街 报子胡同 白塔寺 丰盛胡同 辟才胡同 太平桥 民族文化宫 新文化街 宣武门内 六部口 
                         和平门''',
                         busline8=u'''东单 崇文门 磁器口 榄杆市 培新街 幸福大街 北京体育馆 光明楼''',
                         busline9=u'''金台路 水碓子 小庄 呼家楼 光华路 大北窑 永安里 日坛路 北京站 崇文门 台基厂 正义路 前门''',
                         busline10=u'''复兴门 民族文化宫 西单 六部口 中山公园 天安门 王府井 东单 北京站口 北京站 ''',
                         busline11=u'''大北窑 郎家园 八王坟 火车站 九龙山 化工路西口 化工厂 大郊亭北站 东石门 唐家村 四根旗杆 方家村 半壁店 ''',
                         busline12=u'''五间楼 横七条 铁匠营 方庄南口 方庄 八里河 左安门 游泳池 北京游乐园 光明楼 夕照寺 广渠门''',
                         busline13=u'''三里河 三里河东口 社会路 儿童医院 月坛 阜外大街 阜成门 白塔寺 西四 报子胡同 平安里 厂桥 东官房 北海后门 地安门 罗鼓巷 宽街 十条 船板胡同 
                         北新桥 国子监 雍和宫 北小街豁口 和平里南口 和平里 和平里商锄和平街北口''',
                         busline14=u'''角门南站 角门 西马厂北口 马家堡东口 洋桥 四通路 游泳池 太平街 虎坊桥 琉璃厂 和平门 六部口 力学胡同 灵境胡同 府右街 西安门 后库'''
                         )
bj_subway = update_subway(bj_subway)


def shorter_path(start, goal):
    """
   实现最短路径的搜索
    """
    if start == goal:
        return [start]
    explored = set()
    queue = [[start]]
    while queue:
        path = queue.pop(0)
        s = path[-1]
        for state, action in bj_subway[s].items():
            if state not in explored:
                explored.add(state)
                path2 = path + [action, state]
                if state == goal:
                    return path2
                else:
                    queue.append(path2)
    print(queue[0])
    # for i in range(len(queue)):
    #     print (queue[i])
    # return []


def path_search(start, goal):
    """在最短路径搜索的基础上实现最少换乘次数."""
    if start == goal:
        return [start]
    explored = set()
    queue = [[start, ('', 0)]]
    while queue:
        path = queue.pop(0)
        s = path[-2]
        linenum, changetimes = path[-1]
        if s == goal:
            return path
        for state, action in bj_subway[s].items():
            if state not in explored:
                linechange = changetimes
                explored.add(state)
                if linenum != action:
                    linechange += 1
                path2 = path[:-1] + [action, state, (action, linechange)]
                queue.append(path2)
                queue.sort(key=lambda path: path[-1][-1])
    return []


def find_path(here, there, system=bj_subway):
    """
    输出最佳路线（乘车占数最少）
    """
    min_change_path = path_search(here, there)[::2]
    short_path = shorter_path(here, there)[::2]
    if len(min_change_path) <= len(short_path):
        print(path_search(here, there))
    else:
        print(shorter_path(here, there))



start = input('请输入您的起始位置： ')
goal = input('请输入您的目的地: ')
selection = input('最短路径请输1，最少换乘请输2： ')
if selection == '1':
    print('最短路径方案为：')
    print(shorter_path(start, goal))
elif selection == '2':
    print('最少换乘方案为：')
    print(path_search(start, goal))
else:
    pass
print('我们推荐以下路径：')
print(find_path(start, goal, system=bj_subway))

