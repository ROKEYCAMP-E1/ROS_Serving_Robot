import sqlite3

# 데이터베이스 연결 (파일로 저장되며, 파일 이름은 예시로 'example.db')
conn = sqlite3.connect('order.db')
cursor = conn.cursor()


create_table_query = '''
CREATE TABLE IF NOT EXISTS customer_order (
    
    datetime TEXT ,    
    uuid TEXT PRIMARY KEY,          -- UUID (고유 식별자)
    menu_name TEXT,
    quantity INTEGER,               
    total_price INTEGER
    
)
'''
# 테이블 생성
cursor.execute(create_table_query)

# 변경 사항 저장
conn.commit()