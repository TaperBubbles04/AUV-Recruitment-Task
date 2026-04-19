from setuptools import find_packages, setup

package_name = 'auv_recruitment'

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
    maintainer='root',
    maintainer_email='tharusuresh249@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'task1 = auv_recruitment.task1:main',
            'task2_pub = auv_recruitment.task2_pub:main',
            'task2_process = auv_recruitment.task2_process:main',
            'task2_out = auv_recruitment.task2_out:main'
        ],
    },
)
