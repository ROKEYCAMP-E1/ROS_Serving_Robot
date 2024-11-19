from setuptools import find_packages
from setuptools import setup

setup(
    name='ros_study_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('ros_study_msgs', 'ros_study_msgs.*')),
)
