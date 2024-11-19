from setuptools import find_packages, setup

package_name = 'serving_robot'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='kimdahun',
    maintainer_email='kimdahun@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'customer = serving_robot.customer.customer:main',
            'customer2 = serving_robot.customer.customer2:main',
            'customer3 = serving_robot.customer.customer3:main',
            'customer4 = serving_robot.customer.customer4:main',
            'customer5 = serving_robot.customer.customer5:main',
            'customer6 = serving_robot.customer.customer6:main',
            'customer7 = serving_robot.customer.customer7:main',
            'customer8 = serving_robot.customer.customer8:main',
            'customer9 = serving_robot.customer.customer9:main',
            'kitchen = serving_robot.kitchen.kitchen:main',
            # 'kitchen1= serving_robot.kitchen.kitchen1:main',
            'kitchen_ori = serving_robot.kitchen.kitchencopy:main',
            'robotui = serving_robot.robotui.robotui:main',
            
            
        ],
    },
)
