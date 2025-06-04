import time

def get_lidar_data():
   
    return [1.0, 2.0, 3.0]

def lidar_data_stream():

    while True:
        lidar_data = get_lidar_data()
        yield lidar_data
        time.sleep(0.5)

def process_lidar_data(data):
 
    print("Lidar data being processed:", data)

for lidar_data in lidar_data_stream():
    process_lidar_data(lidar_data)
