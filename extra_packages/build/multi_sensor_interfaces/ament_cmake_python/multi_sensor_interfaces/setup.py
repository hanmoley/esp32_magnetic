from setuptools import find_packages
from setuptools import setup

setup(
    name='multi_sensor_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('multi_sensor_interfaces', 'multi_sensor_interfaces.*')),
)
