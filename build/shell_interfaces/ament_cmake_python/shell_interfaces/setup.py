from setuptools import find_packages
from setuptools import setup

setup(
    name='shell_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('shell_interfaces', 'shell_interfaces.*')),
)
