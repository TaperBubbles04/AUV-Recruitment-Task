from setuptools import find_packages
from setuptools import setup

setup(
    name='auv_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('auv_interfaces', 'auv_interfaces.*')),
)
