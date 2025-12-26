from setuptools import setup, find_packages
package_name = 'shell_test_nodes'

setup(
    name=package_name,
    version='0.0.0',
    packages= find_packages(),
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='esraamustafa',
    maintainer_email='esraaaboelkhair8@gmail.com',
    description='Fake nodes for testing global planner',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'fake_perception = shell_test_nodes.fake_perception:main',
            'fake_localization = shell_test_nodes.fake_localization:main',
            'fake_supervisor = shell_test_nodes.fake_supervisor:main',
            'fake_control = shell_test_nodes.fake_control:main',
        ],
    },
)
