import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import font_manager, rc

# CSV 파일 읽기
data = pd.read_csv('hon.csv', encoding='cp949')

# 한글 폰트 설정
font_path = "C:/Windows/Fonts/malgun.ttf"
font_name = font_manager.FontProperties(fname=font_path).get_name()
rc('font', family=font_name)

# '역번호'가 1과 2이고 '상하구분'이 '외선'인 데이터 필터링
filtered_data = data[(data['출발역'] == '성수') & (data['상하구분'] == '외선')].copy()

# 05시 30분, 00시 30분의 데이터와 인덱스 삭제
filtered_data = filtered_data.drop(['5시30분', '00시30분','00시00분'], axis=1)

# 시간열 선택
time_columns = filtered_data.columns[6:]

# 날짜별로 데이터 분류하기 (평일, 토요일, 공휴일)
weekday_data = filtered_data[filtered_data['요일구분'] == '평일']
saturday_data = filtered_data[filtered_data['요일구분'] == '토요일']
holiday_data = filtered_data[filtered_data['요일구분'] == '공휴일']

# 시간열을 30분 간격으로 묶어 평균 계산
average_weekday = []
average_saturday = []
average_holiday = []
average_time_list = [time.split('시')[0] + '시' for time in time_columns if time.endswith('00분')]
print(average_time_list)

for i in range(0, len(time_columns), 2):
    start_index = filtered_data.columns.get_loc(time_columns[i])
    end_index = filtered_data.columns.get_loc(time_columns[i + 1]) + 1
    average_weekday.append(weekday_data.iloc[:, start_index:end_index].mean(axis=1).values[0])
    average_saturday.append(saturday_data.iloc[:, start_index:end_index].mean(axis=1).values[0])
    average_holiday.append(holiday_data.iloc[:, start_index:end_index].mean(axis=1).values[0])
print(average_weekday)
# 시간대별 데이터 시각화
plt.figure(figsize=(12, 6))
plt.plot(range(0, len(time_columns), 2), average_weekday, label='평일')
plt.plot(range(0, len(time_columns), 2), average_saturday, label='토요일')
plt.plot(range(0, len(time_columns), 2), average_holiday, label='공휴일')

plt.title('구의역 외선 특정 시간대별 평균 승객 수')
plt.xlabel('시간')
plt.ylabel('평균 승객 수')
plt.legend()
plt.xticks(range(0, len(time_columns), 2), [time_columns[i] for i in range(0, len(time_columns), 2)], rotation=45)
plt.grid(True)

# 값 표시
for i in range(len(average_weekday)):
    plt.text(i * 2, average_weekday[i], f'{average_weekday[i]:.2f}', ha='right', va='bottom', fontsize=8, color='blue')
    plt.text(i * 2, average_saturday[i], f'{average_saturday[i]:.2f}', ha='right', va='bottom', fontsize=8, color='orange')
    plt.text(i * 2, average_holiday[i], f'{average_holiday[i]:.2f}', ha='right', va='bottom', fontsize=8, color='green')

plt.show()